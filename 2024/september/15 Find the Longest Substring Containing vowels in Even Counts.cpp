// 1371. Find the Longest Substring Containing vowels in Even Counts
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR = 0;
        // Store the masks of all letters in an array.
        int characterMap[26] = {0};
        characterMap['a' - 'a'] = 1;
        characterMap['e' - 'a'] = 2;
        characterMap['i' - 'a'] = 4;
        characterMap['o' - 'a'] = 8;
        characterMap['u' - 'a'] = 16;
        
        // Initialize map to store the previous index with this prefixXOR value.
        vector<int> map(32, -1);
        int longestSubstring = 0;

        for (int i = 0; i < s.length(); i++) {
            // If the current character is a vowel, find it's prefix XOR and add
            // it in the map
            prefixXOR ^= characterMap[s[i] - 'a'];
            if (map[prefixXOR] == -1 and prefixXOR != 0) {
                map[prefixXOR] = i;
            }
            // If the value of prefixXOR exists in the map, find the longest
            // subarray.
            longestSubstring = max(longestSubstring, i - map[prefixXOR]);
        }
        return longestSubstring;        
    }
};
