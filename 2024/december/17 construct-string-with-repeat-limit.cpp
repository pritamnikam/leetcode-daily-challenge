// 2182. construct-string-with-repeat-limit
// https://leetcode.com/problems/construct-string-with-repeat-limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // get the frequency for every char
        unordered_map<char, int> freq;
        for (char ch: s) {
            freq[ch]++;
        }

        // Max heap to hold the char in reverse chronology, i.e. 'z', 'y'..'a'
        priority_queue<char> pq;
        for (auto& [ch, count]: freq) {
            pq.push(ch);
        }

        string result;
        while (!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            int count = freq[ch];

            // append max allowed repeate counter
            int use = min(count, repeatLimit);
            result.append(use, ch);
            freq[ch] -= use;

            // add next lower ascci value char
            if (freq[ch] > 0 && !pq.empty()) {
                char nextCh = pq.top();
                pq.pop();

                result.push_back(nextCh);
                freq[nextCh]--;

                if (freq[nextCh]> 0) {
                    pq.push(nextCh);
                }

                pq.push(ch);
            }
        }
        return result;
    }
};
