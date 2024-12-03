// 2109. Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size() + spaces.size());

        int spaceIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' ';
                ++spaceIndex;
            }

            result += s[i];
        }

        return result;
    }
};
