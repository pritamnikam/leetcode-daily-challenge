// delete-columns-to-make-sorted-iii
// https://leetcode.com/problems/delete-columns-to-make-sorted-iii

class Solution(object):
    def minDeletionSize(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        w = len(strs[0])
        dp = [1] * w
        for i in xrange(w-2, -1, -1):
            for j in xrange(i+1, w):
                if all(row[i] <= row[j] for row in strs):
                    dp[i] = max(dp[i], 1 + dp[j])
        return w - max(dp)
        
