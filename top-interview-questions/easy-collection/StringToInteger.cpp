/*
String to Integer (atoi)

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.


Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.


Constraints:

0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

*/
/*
func myAtoi(s string) int {
	// Remove any additional spaces before and after the given string
	s = strings.Trim(s, " ")

	n := len(s)

	// If string is empty return 0
	if n == 0 {
		return 0
	}

	// String index from where the processing should start
	var start int

	// Handling numbers with +/- sign
	signMultiplier := 1
	if s[0] == '-' {
		// Handling for negative numbers
		signMultiplier = -1
		start = 1
	} else if s[0] == '+' {
		// Handling for signed positive number
		start = 1
	}

	// ASCII of '0' = 48
	// s[i] - '0' gives the actual number as an integer
	var res int
	for i := start; i < len(s); i++ {
		// Handling for non numeric values
		if !(s[i] >= '0' && s[i] <= '9') {
			return res * signMultiplier
		}

		// Calculate the result for current iteration
		res = res*10 + int(s[i]-'0')

		// Check if result exceeds MinInt32 or MaxInt32
		if res*signMultiplier <= math.MinInt32 {
			return math.MinInt32
		} else if res*signMultiplier >= math.MaxInt32 {
			return math.MaxInt32
		}
	}
	return res * signMultiplier
}
*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int myAtoi(string s) {
        int isNegative = 1;
        bool signProvided = false;
        long result = 0;
        for (auto ch : s) {
            // remove leading spaces
            if (ch == ' ')
                continue;

            if (ch == '-' && !signProvided) {
                isNegative = -1;
                signProvided = true;
                continue;
            }
            else if (ch == '+' && !signProvided) {
                isNegative = 1;
                signProvided = true;
                continue;
            }

            if (ch < '0' || ch > '9') {
                return 0;
            }

            result = 10 * result + int(ch - '0');

            // Check if result exceeds MinInt32 or MaxInt32
            if (result * isNegative <= INT_MIN) {
                return INT_MIN;
            }
            else if (result * isNegative >= INT_MAX) {
                return INT_MAX;
            }
        }

        return result * isNegative;
    }
};