// 440. Kth Smallest in Lexicographical Order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        --k;

        while (k > 0) {
            int steps = countSteps(
                n,
                current,
                current + 1
            );
            if (steps <= k) {
                ++current;
                k -= steps;
            } else {
                current *= 10;
                --k;
            }
        }

        return current;
    }

private:
    int countSteps(
        int n,
        long prefix1,
        long prefix2
    ) {
        int steps = 0;
        while (prefix1 <= n) {
            steps += min((long) n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return steps;
    }
};
