/*
91. Decode Ways
https://leetcode.com/problems/decode-ways/

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").


Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>

namespace {
	class Solution {
	public:
		int numDecodings(string s) {
			if (s.empty() 
				or s[0] == '0') {
				return 0;
			}

			int one_back = 1, 
				two_back = 1, 
				N = s.length();

			for (int i = 1; i < N; ++i) {
				int current = 0;
				if (s[i] != '0') {
					current = one_back;
				}

				int two_digits = stoi(s.substr(i - 1, 2));
				if (two_digits >= 10 and two_digits <= 26) {
					current += two_back;
				}

				two_back = one_back;
				one_back = current;
			}

			return one_back;
		}
    
    int numDecodings1(string s) {
        return numDecodings(s, 0);
    }
    
    unordered_map<int, int> cache;
    int numDecodings(string s, int index) {
        // if already know the answer at index
        if (cache.count(index))
            return cache[index];
        
        // If you reach the end of the string
        // Return 1 for success.
        if (index == s.length())
            return 1;
        
        // If the string starts with a zero, it can't be decoded
        if (s[index] == '0')
            return 0;
        
        // We can not go for 2 char decode, so only one soltion possible
        if (index == s.length()-1)
            return 1;
        
        // we have two options:
        // consider it as single char to decode
        // cosider it as 2 chars to decode
        int ans = numDecodings(s, index + 1);
        if (stoi(s.substr(index, 2)) <= 26) {
            ans += numDecodings(s, index + 2);
        }
        
        cache[index] = ans;
        return ans;
    }
    
    int numDecodings2(string s) {
        if (s[0] == '0') {
            return 0;
        }
        
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1; dp[1] = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != '0') {
                dp[i+1] += dp[i];
            }
            
            if (stoi(s.substr(i-1, 2)) <= 26) {
                dp[i+1] += dp[i-1];
            }
        }
        
        return dp[s.length()];
    }
    
	};
}

void testDecodeWays() {
	cout << "Decode Ways: " << Solution().numDecodings("12") << endl;
	cout << "Decode Ways: " << Solution().numDecodings("226") << endl;
	cout << "Decode Ways: " << Solution().numDecodings("06") << endl;
}
