/*
68. Text Justification
https://leetcode.com/problems/text-justification/description/
*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
    class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> result;
            vector<string> current;
            int numLen = 0;
            for (string word : words) {
                if (word.size() + current.size() + numLen > maxWidth) {
                    for (int i = 0; i < maxWidth - numLen; i++) {
                        current[i % (current.size() - 1 ? current.size() - 1 : 1)] += ' ';
                    }
                    result.push_back("");
                    for (string s : current) result.back() += s;
                    current.clear();
                    numLen = 0;
                }
                current.push_back(word);
                numLen += word.size();
            }
            string lastLine = "";
            for (string s : current) lastLine += s + ' ';
            lastLine = lastLine.substr(0, lastLine.size() - 1);
            while (lastLine.size() < maxWidth) lastLine += ' ';
            result.push_back(lastLine);
            return result;
        }
    };

} // namespace
