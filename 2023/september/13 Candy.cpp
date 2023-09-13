class Solution {
public:
    int candy1(vector<int>& ratings) {
        
        // give everyone a candy in the beginning
        vector<int> candies(ratings.size(), 1);
        
        bool hasChanged = false;
        do {
            hasChanged = false;
            
            // if rating of i is more than i+1 and has lesser candies
            for (int i = 0; i < ratings.size(); ++i) {
                if (i <  ratings.size() - 1 && 
                    ratings[i] > ratings[i+1] && 
                    candies[i] <= candies[i+1]) {
                    candies[i] = 1 + candies[i+1];
                    hasChanged = true;
                }
                
                // if rating of i is more than i-1 and has lesser candies
                if (i > 0 && 
                    ratings[i] > ratings[i-1] && 
                    candies[i] <= candies[i-1]) {
                    candies[i] = 1 + candies[i-1];
                    hasChanged = true;
                }
            }
            
        } while(hasChanged);
        
        int sum = 0;
        for (int n: candies)
            sum += n;
        
        return sum;
    }
    
    // Approach 2: Using two arrays
    // Time complexity : O(n)
    // Space complexity : O(n)
    int candy2(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftToRight(n, 1), rightToLeft(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (ratings[i-1] < ratings[i] && leftToRight[i-1] >= leftToRight[i]) {
                leftToRight[i] = 1+ leftToRight[i-1];
            }
        }
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i+1] < ratings[i] && rightToLeft[i+1] >= rightToLeft[i]) {
                rightToLeft[i] = 1 + rightToLeft[i+1];
            }
        }
        
        int sum = 0;
        for (int i =0; i < n; ++i) {
            sum += max(leftToRight[i], rightToLeft[i]);
        }
        
        return sum;
    }
    
    // Approach 3: Using one array
    // Time complexity : O(n)
    // Space complexity : O(n)
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (ratings[i-1] < ratings[i])
                candies[i] = 1 + candies[i-1];
        }
        
        for (int i = n-2; i>=0; --i) {
            if (ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], 1 + candies[i+1]);
        }        
        
        int sum = 0;
        for (int n: candies)
            sum += n;
        
        return sum;
    }
};
