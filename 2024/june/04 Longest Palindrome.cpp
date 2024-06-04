// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for (char c: s)
            map[c]++;
        
        int ans = 0;
        for (auto it: map) {
            ans += it.second / 2 * 2;
            if(ans % 2 == 0 && it.second % 2 == 1)
                ++ans;
        }
        
        return ans;
    }
};
