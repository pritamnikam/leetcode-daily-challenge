class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    // Let B = int(minutesToTest / minutesToDie) + 1
    // Find x such that B^x > buckets
    int B = int(minutesToTest / minutesToDie) + 1;
    return ceil(log2(buckets) / logs2(B));
  }
};
