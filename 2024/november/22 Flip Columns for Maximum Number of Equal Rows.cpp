// 1072. Flip Columns for Maximum Number of Equal Rows
// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // map for frequency of each pattern
        unordered_map<string, int> patternFrequency;

        for (auto& currentRow: matrix) {
            string patternBuilder = "";

            // convert row to pattern relative to its first element
            for (int col = 0; col < currentRow.size(); col++) {
                // 'T' if 1st element matches to current; 'F' otherwise
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }

            // Convert pattern to string & update its frequency in map
            patternFrequency[patternBuilder]++;
        }

        // Find the pattern with max frequency
        int maxFrequency = 0;
        for (auto& entry: patternFrequency) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};
