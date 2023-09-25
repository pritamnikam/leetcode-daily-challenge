// 389. Find The Difference
// https://leetcode.com/problems/find-the-difference

using namespace std;

namespace {

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> arr(26, 0);
        for (char ch: s) {
            arr[ch-'a']++;
        }

        for (char ch: t) {
            arr[ch-'a']--;
        }

        char ch;
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {ch = i + 'a'; break;}
        }

        return ch;
    }
};

} // namespace
