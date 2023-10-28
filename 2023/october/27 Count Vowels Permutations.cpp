// 1220. Count Vowels Permutations
// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:
    int countVowelPermutationDP(int n) {
        vector<int> aVowelPermutationCount(n),
                    eVowelPermutationCount(n),
                    iVowelPermutationCount(n),
                    oVowelPermutationCount(n),
                    uVowelPermutationCount(n);
        
        aVowelPermutationCount[0] = 1,
        eVowelPermutationCount[0] = 1,
        iVowelPermutationCount[0] = 1,
        oVowelPermutationCount[0] = 1,
        uVowelPermutationCount[0] = 1;
        
        int MOD = 1000000007;
        
        /*
            aCountNew = eCount + iCount + uCount
            eCountNew = aCount + iCount
            iCountNew = eCount + oCount
            oCountNew = iCount
            uCountNew = iCount + oCount
        */
        
        for (int i = 1; i < n; ++i) {
            aVowelPermutationCount[i] = 
                (eVowelPermutationCount[i - 1] + 
                 iVowelPermutationCount[i - 1] + 
                 uVowelPermutationCount[i - 1]) % MOD;
            
            eVowelPermutationCount[i] = 
                (aVowelPermutationCount[i - 1] + 
                 iVowelPermutationCount[i - 1]) % MOD;
            
            iVowelPermutationCount[i] = 
                (eVowelPermutationCount[i - 1] + 
                 oVowelPermutationCount[i - 1]) % MOD;
            
            oVowelPermutationCount[i] = 
                iVowelPermutationCount[i - 1] % MOD;
            
            uVowelPermutationCount[i] = 
                (iVowelPermutationCount[i - 1] + 
                 oVowelPermutationCount[i - 1]) % MOD;
        }
        
        long result = 0L;

        result = 
            (aVowelPermutationCount[n - 1] + 
             eVowelPermutationCount[n - 1] +
             iVowelPermutationCount[n - 1] + 
             oVowelPermutationCount[n - 1] + 
             uVowelPermutationCount[n - 1]) % MOD;

        return (int)result;
    }
    
    
    int countVowelPermutation(int n) {
        long aCount = 1, 
             eCount = 1, 
             iCount = 1, 
             oCount = 1,
             uCount = 1;
        
        int MOD = 1000000007;
        
        for (int i = 1; i < n; ++i) {
            long aCountNew = (eCount + iCount + uCount) % MOD;
            long eCountNew = (aCount + iCount) % MOD;
            long iCountNew = (eCount + oCount) % MOD;
            long oCountNew = (iCount) % MOD;
            long uCountNew = (iCount + oCount) % MOD;
            
            aCount = aCountNew;
            eCount = eCountNew;
            iCount = iCountNew;
            oCount = oCountNew;
            uCount = uCountNew;
        }
  
        long result = 
            (aCount + 
             eCount + 
             iCount + 
             oCount + 
             uCount)  % MOD;
        
        return (int)result;
    }
};
