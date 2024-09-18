// 18 Largest Number
// https://leetcode.com/problems/largest-number

class Solution {

static bool Compare(const string& a, const string& b) {
    return a+b > b+a;
}

public:
    string largestNumber(vector<int>& nums) {
        vector<string> vt;
        for (int n: nums) {
            vt.push_back(to_string(n));
        }

        sort(vt.begin(), vt.end(), Compare);
        
        string result;
        for (string n: vt)
            result += n;
        
        if (result < "1")
            result = "0";
        
        return result;
    }
};
