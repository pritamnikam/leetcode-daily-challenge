// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int start = 0;
        int end = 0;
        
        int k = s1.length();
        int distinctLetters = 0;
        unordered_map<char, int> window;
        
        for (char ch: s1){
            window[ch]++;
            if (window[ch] == 1){
                distinctLetters++;
            }
        }
        
        
        while (end < s2.length()) {
            auto it = window.find(s2[end]);
            if (it != window.end()) {
                window[s2[end]]--;
                if (window[s2[end]] == 0) {
                    distinctLetters--;
                }
            }
            
            if (end - start + 1 <k) {
                end++;
            } else {
                if (distinctLetters == 0) {
                    return true;
                }
                
                if (window.find(s2[start]) != window.end()) {
                    window[s2[start]]++;
                    if (window[s2[start]] == 1)
                        distinctLetters++;
                }
                
                start++;
                end++;
            }
            
        }
        
        return false;
    }
};
