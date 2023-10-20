// 341. Flattern Nested List Iterator
// https://leetcode.com/problems/flatten-nested-list-iterator/

using namespace std;

#include <iostream>
#include <vector>

namespace {

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger>& nestedList) {
    current = 0;
    flattenIntegers(nestedList);
  }

  int next() {
    return integers[current++];
  }

  bool hasNext() {
    return current < integers.size();
  }

private:
  int current;
  vector<int> integers;

  // recurrsive
    void flattenIntegers(vector<NestedInteger> &nestedList) {
        for (NestedInteger& nestedInteger: nestedList) {
            if (nestedInteger.isInteger()) {
                integers.push_back(nestedInteger.getInteger());
            } else {
                flattenIntegers(nestedInteger.getList());
            }
        }
    }
};

} // namespace
