/*
67. Add Binary
https://leetcode.com/problems/add-binary/discussion/

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"


Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

*/

using namespace std;

#include <iostream>
#include <string>

namespace {

    class Solution {
    public:
        string addBinary(string a, string b) {
            if (b.size() > a.size()) swap(a, b);
            while (b.size() < a.size()) b = "0" + b;
            int carry = 0;
            string res = "";

            // RTL
            for (int i = b.size() - 1; i >= 0; --i) {
                if (b[i] == '1' && a[i] == '1') {
                    if (carry == 0) res = "0" + res;
                    else res = "1" + res;
                    carry = 1;
                }

                else if (b[i] == '0' && a[i] == '0') {
                    if (carry == 0) res = "0" + res;

                    else {
                        res = "1" + res;
                        carry = 0;
                    }
                }

                else if ((b[i] == '0' && a[i] == '1') || (b[i] == '1' && a[i] == '0')) {
                    if (carry == 0) res = "1" + res;
                    else res = "0" + res;
                }
            }

            if (carry == 1) res = "1" + res;
            return res;
        }
    };

} // namespace

void testAddBinary() {
    /*
        Example 1:
        Input: a = "11", b = "1"
        Output: "100"
    */

    string a = "11", b = "1";
    cout << "Add Binary: " << Solution().addBinary(a, b) << endl;
}
