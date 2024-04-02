// 205. Isomorphic Strings
// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        int i = 0,
            n = s.length();
        
        unordered_map<char, int> s_t_Map, t_s_Map;
        
        
        // 1. If the characters don't have a mapping, we add one in the dictionary and move on.
        // 2. The characters already have a mapping in the dictionary. If that is the case, then we're good to go.
        // 3. The final case is when a mapping already exists for one of the characters but it doesn't map to the other character at hand. In this case, we can safely conclude that the given strings are not isomorphic and we can return.
        while (i < n) {
            if ((!s_t_Map.count(s[i]) and !t_s_Map.count(t[i])) or
                (s_t_Map[s[i]] == t[i] and t_s_Map[t[i]] == s[i])) {
                s_t_Map[s[i]] = t[i];
                t_s_Map[t[i]] = s[i];
                ++i;
            } else {
                return false;
            }            
        }
        
        return true;        
    }
};
