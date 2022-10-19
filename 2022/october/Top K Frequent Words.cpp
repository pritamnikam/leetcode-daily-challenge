/*
692. Top K Frequent Words
https://leetcode.com/problems/top-k-frequent-words/

Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with
the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.


Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

using namespace std;

#include <vector>
#include <map>
#include <string>
#include <queue>

namespace {
	struct Compare {
		bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
			if (a.second == b.second) return a.first < b.first;
			return a.second > b.second;
		}
	};

	class Solution {
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			map<string, int> wordCount;
			for (string word : words) {
				wordCount[word]++;
			}

			priority_queue<
				pair<string, int>,
				vector<pair<string, int>>,
				Compare> minHeap;

			for (auto& it : wordCount) {
				minHeap.push(it);
				if (minHeap.size() > k) {
					minHeap.pop();
				}
			}

			vector<string> answer;
			while (!minHeap.empty()) {
				answer.push_back(minHeap.top().first);
				minHeap.pop();
			}

			reverse(begin(answer), end(answer));
			return answer;
		}
	};


}  // namespace

void testTopKFrequent() {
	vector<string> words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
	int k = 4;

	vector<string> ans = Solution().topKFrequent(words, k);
}
