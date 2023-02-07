/*
904. Fruit Into Baskets
https://leetcode.com/problems/fruit-into-baskets/submissions/893323132/

You are visiting a farm that has a single row of fruit trees arranged from left to right. 
The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
1. You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
2. Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
3. Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:
1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
	class Solution {
	public:
		int totalFruit(vector<int>& fruits) {
            unordered_map<int, int> fruitFreqMap;
            int windowStart = 0;
            int k = 2;
            int windowLength = 0;
            for (int windowEnd = 0; windowEnd < fruits.size(); ++windowEnd) {
                fruitFreqMap[fruits[windowEnd]]++;

                // we already have more than 2 types of fruits in basket
                // shrink the window
                if (fruitFreqMap.size() > k) {
                    fruitFreqMap[fruits[windowStart]]--;
                    if (fruitFreqMap[fruits[windowStart]] == 0)
                        fruitFreqMap.erase(fruits[windowStart]);

                    ++windowStart;
                }

                windowLength = max(windowLength, windowEnd - windowStart + 1);
            }

            return windowLength;
		}
	};

} // namespace

void testFruitIntoBaskets() {
    // Input: fruits = [1,2,1], Output: 3
    vector<int> fruits = { 1, 2, 1 };
    cout << "Fruit Into Baskets: " << Solution().totalFruit(fruits) << endl;
}
