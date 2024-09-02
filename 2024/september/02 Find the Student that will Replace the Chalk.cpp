// 1894. Find the Student that will Replace the Chalk
// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // find sum of all the elements
        int sum = 0;
        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
            if (sum > k) {
                break;
            }
        }

        k = k % sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }

private:
  int chalkReplacer2(
    vector<int>& chalk,
    int k
  ) {
    int n = chalk.size();
    vector<long> prefixSum(n, 0);
    prefixSum[0] = chalk[0];
    for (int i = 1; i < n; i++) {
      prefixSum[i] = prefixSum[i-1] + chalk[i];
    }

    long sum = prefixSum[n - 1];
    long remainingChalk = (k % sum);

    return binarySearch(prefixSum, remainingChalk);
  }


  int binarySearch(
    vector<int>& arr,
    long target
  ) {
    int lo = 0, 
        hi = arr.size() - 1;

    while (lo < hi) {
      int mid = lo + (hi - lo)/2;
      if (arr[mid] <= target) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return hi;
  }
};
