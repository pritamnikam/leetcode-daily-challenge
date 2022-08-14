/*
* 126. Word Ladder II
https://leetcode.com/problems/word-ladder-ii/

A transformation sequence from word beginWord to word endWord using a dictionary wordList 
is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
- Every adjacent pair of words differs by a single letter.
- Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
- sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest 
transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. 

Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.


*/
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>

namespace {
	class Solution {

		bool areNeibhours(const string& a, const string& b) {
			int cnt = 0;
			for (int i = 0; i < a.length(); i++) {
				if (a[i] != b[i]) {
					cnt++;
				}
			}

			return cnt == 1;
		}

	public:
		vector<vector<string>> findLadders(string beginWord,
										   string endWord,
										   vector<string>& wordList) {

			wordList.insert(wordList.begin(), beginWord);

			for (int i = 1; i < wordList.size(); i++) {
				// string compare
				if (wordList[i] == wordList[0]) {
					wordList[i] = wordList.back();
					wordList.pop_back();
					break;
				}
			}

			map<string, int> wti; // word to index
			for (int i = 0; i < wordList.size(); i++) {
				wti.insert({ wordList[i], i });
			}

			// |endWord| not in map
			if (!wti.count(endWord)) return {};

			// Build graph:
			vector<vector<int>> edges(wti.size());
			for (int i = 0; i < wordList.size(); i++) {
				for (int j = 0; j < wordList.size(); j++) {
					if (i == j) continue;

					if (areNeibhours(wordList[i], wordList[j])) {
						edges[i].push_back(j);
					}
				}
			} // for

			// Perform BFS: level-order traversal
			int start_node = 0,
				target_node = wti[endWord],
				r = 0,
				min_step = INT_MAX;

			queue<int> q;
			vector<int> vis(wordList.size(), INT_MAX);

			vis[start_node] = 0;			
			q.push(start_node);

			while (!q.empty()) {
				int sz = q.size();
				for (int i = 0; i < sz; i++) {
					int fr = q.front();
					q.pop();

					if (fr == target_node) 
						min_step = min(min_step, r);
					
					for (int j = 0; j < edges[fr].size(); j++) {
						int update_node = edges[fr][j];
						if (r + 1 < vis[update_node]) {
							vis[update_node] = r + 1;
							q.push(update_node);
						}
					}
				}

				r++;
			} // while (!q.empty())


			if (min_step == INT_MAX) {
				return {};
			}

			queue<vector<string>> q2;
			q2.push({ wordList[target_node] });
			r = min_step;
			while (r){
				int sz = q2.size();
				for (int i = 0; i < sz; i++) {
					vector<string> seq = q2.front();
					q2.pop();
					string back = seq.back();
					int curr = wti[back];
					for (int j = 0; j < edges[curr].size(); j++){
						int new_node = edges[curr][j];
						if (vis[new_node] == r - 1)	{
							seq.push_back(wordList[new_node]);
							q2.push(seq);
							seq.pop_back();
						}
					}
				}
				r--;
			}
			vector<vector<string>> ans;
			while (!q2.empty())	{
				vector<string> temp = q2.front();
				q2.pop();
				reverse(begin(temp), end(temp));
				ans.push_back(temp);
			}
			return ans;
		}
	};
}