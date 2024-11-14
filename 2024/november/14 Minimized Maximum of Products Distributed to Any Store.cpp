// 2064. Minimized Maximum of Products Distributed to Any Store
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // init the boundaries of binary search
        int left = 0, 
            right = *max_element(quantities.begin(), quantities.end());

        //Perform a binary search
        while (left < right) {
            int mid = left + (right - left)/2;
            if (canDistribute(mid, quantities, n)) {
                // try for a smaller maximum
                right = mid;
            } else {
                //Increase the minimum possible maximum
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canDistribute(int x, vector<int>& quantities, int n) {
        // pointer to the first not fully distributed product type
        int j = 0;

        // remaining quantities
        int remaining = quantities[j];

        for (int i = 0; i < n; i++) {
            if (remaining <= x) {
                j++;
                if (j == quantities.size()) {
                    return true;
                } else {
                    remaining = quantities[j];
                }
            } else {
                remaining -= x;
            }
        }
        return false;
    }
};
