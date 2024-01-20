// Sum of Subarray Minimum
// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // left is for the distance to previous less element
        // right is for the distance to next less element
        vector<int> left(arr.size()), 
                    right(arr.size());

        //initialize
        for (int i = 0; i < arr.size(); i++) 
            left[i] = i + 1;

        for (int i = 0; i < arr.size(); i++) 
            right[i] = arr.size() - i;

        stack<pair<int, int>> in_stk_p, 
                              in_stk_n;
        for (int i = 0; i < arr.size(); i++) {
            // for previous less
            while (!in_stk_p.empty() 
                   && in_stk_p.top().first > arr[i]) {
                in_stk_p.pop();
            }

            left[i] = in_stk_p.empty() 
                ? i + 1 
                : i - in_stk_p.top().second;
            
            in_stk_p.push({ arr[i],i });

            // for next less
            while (!in_stk_n.empty() 
                   && in_stk_n.top().first > arr[i]) {
                auto x = in_stk_n.top(); 
                in_stk_n.pop();
                
                right[x.second] = i - x.second;
            }

            in_stk_n.push({ arr[i], i });
        }

        long long ans = 0, 
                  mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            ans = (ans +
                   ((long long)arr[i] 
                    * (long long)left[i] 
                    * (long long)right[i])) % mod;
        }
        return (int)ans;
    }
};
