/*
875. Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


Constraints:
1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {
	class Solution {
	public:
		int minEatingSpeed(vector<int>& piles, int h) {
			int lo = 1, hi = *max_element(piles.begin(), piles.end());

			while (lo < hi) {
				int speed = lo + (hi - lo) / 2;
				int hoursSpent = 0;

				for (int pile : piles) {
					hoursSpent += (pile / speed) + (pile % speed != 0);
				}

				// go left
				if (hoursSpent <= h) {
					hi = speed;
				}
				// go right
				else {
					lo = speed + 1;
				}
			}

			return hi;
		}
	};
}  // namespace


void testKokoEatingBanans() {
	// Input: piles = [3,6,7,11], h = 8 | Output: 4
	vector<int> piles = { 3, 6, 7, 11 };
	int h = 8;

	cout << "Koko Eating Banans: " << Solution().minEatingSpeed(piles, h) << endl;
}
