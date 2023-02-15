/*
989. Add to Array-Form of Integer
https://leetcode.com/problems/add-to-array-form-of-integer/

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Example 1:
Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:
Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:
Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021


Constraints:
1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
    class Solution {
    public:
        vector<int> addToArrayForm(vector<int>& num, int k) {
            vector<int> num2 = toVector(k);
            return addToArrayForm(num, num2);
        }

        vector<int> addToArrayForm2(vector<int>& num, int k) {
            for (int i = num.size() - 1; i >= 0; --i) {
                num[i] += k;
                k = num[i] / 10;
                num[i] %= 10;
            }

            while (k > 0) {
                num.insert(begin(num), k % 10);
                k /= 10;
            }
            return num;
        }

    private:
        vector<int> toVector(int k) {
            vector<int> num;
            while (k) {
                num.emplace_back(k % 10);
                k = k / 10;
            }

            reverse(num.begin(), num.end());
            return num;
        }

        vector<int> addToArrayForm(vector<int>& a, vector<int>& b) {
            if (b.size() > a.size()) {
                return addToArrayForm(b, a);
            }

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());

            while (b.size() < a.size()) {
                b.emplace_back(0);
            }

            vector<int> res;
            int carry = 0;
            for (int i = 0; i < b.size(); ++i) {
                int sum = a[i] + b[i] + carry;
                res.emplace_back(sum % 10);
                carry = sum / 10;
            }

            if (carry) res.emplace_back(carry);
            reverse(res.begin(), res.end());
            return res;
        }
    };
} // namespace

void testAddToArrayFormOfInteger() {
    /*
    * Example 1: Input: num = [1,2,0,0], k = 34 | Output: [1,2,3,4]
    */
    vector<int> num = { 1, 2, 0, 0 };
    int  k = 34;

    vector<int> output = Solution().addToArrayForm(num, k);

}
