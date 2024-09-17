// 539. Minimum Time Difference
// https://leetcode.com/problems/minimum-time-difference/

class Solution {
    const int kHour = 60;
    const int kDay = 24 * 60;

    int toMin(string& time) {
        return stoi(time.substr(0, 2)) * kHour + stoi(time.substr(3));
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        // convert to mins
        vector<int> vt;
        for (string& str: timePoints) {
            vt.push_back(toMin(str));
        }

        // sort in ascending order
        sort(vt.begin(), vt.end());

        // minimum consecative time points
        int answer = numeric_limits<int>::max();
        for (int i = 1; i < vt.size(); ++i) {
            answer = min(answer, vt[i] - vt[i-1]);
        }
        
        // wrap around handling
        answer = min(answer, vt[0] + kDay - vt.back());
        return answer;
    }
};
