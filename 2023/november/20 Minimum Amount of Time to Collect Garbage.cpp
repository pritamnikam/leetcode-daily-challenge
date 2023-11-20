// 2391. Minimum Amount of Time to Collect Garbage
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // store the prefix sum in travel itself
        for (int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i-1];
        }

        // map to store garbage type to the last house index.
        unordered_map<char, int> garbageLastPos;
        int ans = 0;

        for (int i = 0; i < garbage.size(); i++) {
            for (char c: garbage[i]) {
                garbageLastPos[c] = i;
            }
            ans += garbage[i].size();
        }

        string garbageTypes = "MPG";
        for (char c: garbageTypes) {
            // no travel time is required if the last house is at index 0.
            ans += (garbageLastPos[c] == 0 
                        ? 0 
                        : travel[garbageLastPos[c] - 1]);
        }
        return ans;
    }
};
