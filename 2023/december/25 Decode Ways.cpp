// 91. Decode Ways
// https://leetcode.com/problems/decode-ways

class Solution {
public:
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
    
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (size_t i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 and two_digit <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }
        return one_back;
    }
};
