// 2053. Kth Distinct String in an Array
// https://leetcode.com/problems/kth-distinct-string-in-an-array


class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string answer;
        unordered_map<string, int> freqMap;
        for (string& str: arr)
            freqMap[str]++;
        
        int count = 0;
        for (string& str: arr) {
            if (freqMap[str] == 1) {
                count++;
                if (count == k) {
                    answer = str;
                    break;
                }
            }
        }
        
        return answer;
    }
};
