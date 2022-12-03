/*
451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

namespace {
	class Solution {
	public:
		string frequencySort(string s) {
			unordered_map<char, int> frequencyMap;

			for (char ch : s) {
				frequencyMap[ch]++;
			}

			priority_queue<pair<int, char>> heap;
			for (auto& it : frequencyMap) {
				heap.push({ it.second, it.first });
			}

			string str;
			while (!heap.empty()) {
				for (int i = 0; i < heap.top().first; ++i)
					str.push_back(heap.top().second);

				heap.pop();
			}

			return str;
		}
	};

} // namespace

void testSortCharactersByFrequency() {
	// Input: s = "tree" | Output: "eert"
	cout << "Sort Characters By Frequency: " << Solution().frequencySort("tree") << endl;

	// Input: s = "cccaaa" | Output: "aaaccc"
	cout << "Sort Characters By Frequency: " << Solution().frequencySort("cccaaa") << endl;

	// Input: s = "Aabb" | Output: "bbAa"
	cout << "Sort Characters By Frequency: " << Solution().frequencySort("Aabb") << endl;
}
