// 633. Sum of Square Numbers
// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int) (a*a);
            if (binarySearch(0,b,b)) {
                return true;
            }
        }
        return false;
    }

private:
    bool binarySearch(
        long s,
        long e,
        int n
    ) {
        if (s > e) return false;

        long mid = s + (e-s)/2;
        if (mid * mid == n) {
            return true;
        } else if (mid * mid > n) {
            return binarySearch(s, mid - 1, n);
        } else {
            return binarySearch(mid + 1, e, n);
        }
    }
};
