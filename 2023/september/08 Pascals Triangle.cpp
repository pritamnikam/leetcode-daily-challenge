class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0) 
            return result;
        
        // first row is '1'
        vector<int> r;
        result.push_back(r);
        result[0].push_back(1);
        
        for (int i = 1; i < numRows; ++i) {
            // start and end of every row is '1'
            vector<int> t;
            result.push_back(t);
            result[i].push_back(1);
            
            // for every element in a row is the sum of the column and column previous of the previous row
            for (int j = 1; j < i; ++j) {
                int num = result[i - 1][j - 1] + result[i - 1][j];
                result[i].push_back(num);
            }
                                    
            result[i].push_back(1);
        }
        
        return result;
    }
};
