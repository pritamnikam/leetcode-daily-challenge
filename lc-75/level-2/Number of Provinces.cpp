/*
547. Number of Provinces
https://leetcode.com/problems/number-of-provinces/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, 
and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly 
connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/


using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

namespace {

	class FindUnion {
	public:
		FindUnion(int size) : root(size), rank(size, 1) {
			for (int i = 0; i < size; ++i)
				root[i] = i;
		}

		int Find(int x) {
			if (x == root[x]) return x;
			return root[x] = Find(root[x]);
		}

		void Union(int x, int y) {
			int rootX = Find(x), 
				rootY = Find(y);

			if (rootX != rootY) {
				if (rank[rootX] > rank[rootY]) {
					root[rootY] = rootX;
				}
				else if (rank[rootX] < rank[rootY]) {
					root[rootX] = rootY;
				}
				else {
					root[rootY] = rootX;
					rank[rootX] += 1;
				}
			}
		}

		bool connected(int x, int y) {
			return Find(x) == Find(y);
		}

	private:
		vector<int> root;
		vector<int> rank;
	};

	class Solution {
	public:
		int findCircleNum(vector<vector<int>>& isConnected) {
			int size = isConnected.size();
			FindUnion uf(size);

			for (int i = 0; i < size; ++i) {
				for (int j = 0; j < size; ++j) {
					if (isConnected[i][j] and i != j)
						uf.Union(i, j);
				}
			}

			unordered_set<int> set;
			for (int i = 0; i < size; ++i) {
				set.insert(uf.Find(i));
			}

			return set.size();
		}
	};
}

void testNumberOfProvines() {
	vector<vector<int>> isConnected = { 
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1} 
	};

	cout << "Number of Provinces: " << Solution().findCircleNum(isConnected) << endl;

	isConnected = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	cout << "Number of Provinces: " << Solution().findCircleNum(isConnected) << endl;

}