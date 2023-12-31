// 1624. Largest substring Between Two Equal Characters
// https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstIndex;
        int answer = -1;
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex.find(s[i]) != firstIndex.end()) {
                answer = max(answer, i - firstIndex[s[i]] - 1);
            } else {
                firstIndex[s[i]] = i;
            }
        }
        return answer;
    }
};
