// 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        // edge cases:
        if (s.empty() || 
            t.empty() || 
            s.length() < t.length()) {
            return "";
        }

        int matched = 0;
        int start = -1;

        unordered_map<char, int> charFreqMap;
        for (char ch: t) {
            charFreqMap[ch]++;
        }

        int windowSize = s.length();
        int windowStart = 0;

        for (int windowEnd = 0; windowEnd < s.length(); ++windowEnd) {
            char rightChar = s[windowEnd];
            if (charFreqMap.find(rightChar) != charFreqMap.end()) {
                charFreqMap[rightChar]--;

                if (charFreqMap[rightChar] == 0) {
                    ++matched;
                }
            }

            // keep shrinking window from left
            while (matched == charFreqMap.size()) {
                // update window size
                int currentWindowSize = windowEnd - windowStart + 1;
                if (windowSize >= currentWindowSize) {
                    start = windowStart;
                    windowSize = currentWindowSize;
                }

                char leftChar = s[windowStart];
                if (charFreqMap.find(leftChar) != charFreqMap.end()) {
                    if (charFreqMap[leftChar] == 0) {
                        --matched;
                    }

                    charFreqMap[leftChar]++;
                }

                ++windowStart;
            }
        }
        return start == -1 ?
            "" :
            s.substr(start, windowSize); 
    }
};
