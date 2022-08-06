/*
721. Accounts Merge
https://leetcode.com/problems/accounts-merge/

Given a list of accounts where each element accounts[i] is a list of strings, 
where the first element accounts[i][0] is a name, and the rest of the elements 
are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the
same person if there is some common email to both accounts. Note that even if two 
accounts have the same name, they may belong to different people as people could 
have the same name. A person can have any number of accounts initially, but all of
their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: 
the first element of each account is the name, and the rest of the elements are emails
in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]


Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

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
		vector<vector<string>> accountsMerge(vector<vector<string>>& accountList) {
			int accountListSize = accountList.size();
			FindUnion fu(accountListSize);

			// Maps email to their component index
			unordered_map<string, int> emailGroup;

			for (int i = 0; i < accountListSize; i++) {
				int accountSize = accountList[i].size();
				string accountName = accountList[i][0];

				for (int j = 1; j < accountSize; j++) {
					string email = accountList[i][j];
					
					// If this is the first time seeing this email then
					// assign component group as the account index
					if (!emailGroup.count(email)) {
						emailGroup[email] = i;
					}
					else {
						// If we have seen this email before then union this
						// group with the previous group of the email
						fu.Union(i, emailGroup[email]);
					}

				} // for-inner
			} // for-outer

			// Store emails corresponding to the component's representative
			unordered_map<int, vector<string>> components;
			for (auto emailIterator : emailGroup) {
				string email = emailIterator.first;
				int group = emailIterator.second;
				components[fu.Find(group)].push_back(email);
			}

			// Sort the components and add the account name
			vector<vector<string>> mergedAccounts;
			for (auto componentIterator : components) {
				int group = componentIterator.first;
				vector<string> component = { accountList[group][0] };
				component.insert(component.end(), 
								 componentIterator.second.begin(),
								 componentIterator.second.end());
				sort(component.begin() + 1, component.end());
				mergedAccounts.push_back(component);
			}

			return mergedAccounts;
		}
	};
}  // namespace


void testAccountMerge() {
	/*
		
		Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
		Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

	*/

	vector<vector<string>> accounts = {
		{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
		{"John", "johnsmith@mail.com", "john00@mail.com"},
		{"Mary", "mary@mail.com"},
		{"John", "johnnybravo@mail.com"}
	};


	vector<vector<string>> output = Solution().accountsMerge(accounts);

}
