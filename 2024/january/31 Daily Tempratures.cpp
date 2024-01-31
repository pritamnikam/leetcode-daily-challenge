// 739. Daily Tempratures
// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
    // Next bigger element (NGR)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
	    vector<int> vt;
        int n = temperatures.size();
        
        for (int i = n-1; i >= 0; --i) {
            if (st.empty())
                vt.push_back(0);
            
            else if (st.top().first > temperatures[i]) {
			    vt.push_back(st.top().second - i);
		    }
            
            else {
                while (!st.empty() && 
                       st.top().first <= temperatures[i]) {
				    st.pop();
			    }
                
                if (st.empty()) {
				    vt.push_back(0);
                }
                else if (st.top().first > temperatures[i]) {
                    vt.push_back(st.top().second - i);
                }
            }
            
            st.push({temperatures[i], i});
        }
        
        reverse(vt.begin(), vt.end());
        return vt;
    }
};
