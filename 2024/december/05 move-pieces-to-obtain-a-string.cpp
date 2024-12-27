// 2337. move-pieces-to-obtain-a-string
// https://leetcode.com/problems/move-pieces-to-obtain-a-string

class Solution {
public:
    bool canChange(string start, string target) {
        int startLength = start.size();

        // two pointes for start and target
        int startIndex = 0, targetIndex = 0;

        while (
            startIndex < startLength ||
            targetIndex < startLength
        ) {
            // skip blanks in start
            while(
                startIndex < startLength &&
                start[startIndex] == '_'
            ) {
                ++startIndex;
            }

            // skip blanks in target
            while (
                targetIndex < startLength &&
                target[targetIndex] == '_'
            ) {
                ++targetIndex;
            }

            // if one string is exhausted, both should have been exhausted
            if (
                startIndex == startLength ||
                targetIndex == startLength
            ) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // check if pieces match and floow movement rules
            if (
                start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex)
            ) {
                return false;
            }

            ++startIndex;
            ++targetIndex;
        }

        return true;
    }
};
