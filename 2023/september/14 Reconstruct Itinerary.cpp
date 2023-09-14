// 332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, 
                      vector<pair<string, int>>> nodeMap;
        
        for (int i=0; i<tickets.size(); i++)
            nodeMap[tickets[i][0]].push_back({tickets[i][1], i});
        
        for (auto& [k, v] : nodeMap)
            sort(v.begin(), v.end());
        
        unordered_set<int> visited;
        function<bool(const string&, int, vector<string>&)> dfs = [&](const string& node, 
                                                                      int index, 
                                                                      vector<string>& result) {
            if (nodeMap[node].empty() && 
                visited.size() < tickets.size())
                return false;
            
            result.push_back(node);
            visited.insert(index);
            
            if (visited.size() == tickets.size()+1)
                return true;
            
            for (auto& p : nodeMap[node])
                if (visited.find(p.second) == visited.end() && 
                    dfs(p.first, p.second, result))
                    return true;
            
            visited.erase(index);
            result.pop_back();
            return false;
        };
            
        vector<string> result = {};
        dfs("JFK", -1, result);
        return result;
    }
};
