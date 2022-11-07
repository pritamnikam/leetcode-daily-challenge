/*
1323. Maximum 69 Number
https://leetcode.com/problems/maximum-69-number/

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).



Example 1:

Input: num = 9669
Output: 9969
Explanation:
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.


Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.


*/

using namespace std;


#include <iostream>
#include <string>

namespace {
    class Solution {
    public:
        int maximum69Number(int num) {
            int temp = num;
            string str;
            while (temp) {
                int digit = temp % 10;
                temp = temp / 10;
                str += to_string(digit);
            }

            for (int i = str.length() - 1; i >= 0; --i) {
                if (str[i] == '6') {
                    str[i] = '9';
                    break;
                }
            }

            reverse(str.begin(), str.end());
            return stoi(str);
        }


        int maximum69Number2(int num) {
            // Convert the input 'num' to a string 'numString'.
            string numString = to_string(num);

            // Iterate over the string (from high to low).
            for (auto& digit : numString) {
                // If we find the first '6', replace it with '9' and break the loop.
                if (digit == '6') {
                    digit = '9';
                    break;
                }
            }

            // Convert the modified string to integer and return it.
            return stoi(numString);
        }
    };
}

void testMaximum69Number() {
    // Input: num = 9669, Output: 9969
    cout << "" << Solution().maximum69Number2(9669) << endl;
}
