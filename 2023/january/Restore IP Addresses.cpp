/*
93. Restore IP Addresses
https://leetcode.com/problems/restore-ip-addresses/

A valid IP address consists of exactly four integers separated by single dots.
Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312"
and "192.168@1.1" are invalid IP addresses.

Given a string s containing only digits, return all possible valid IP addresses that can be formed by
inserting dots into s. You are not allowed to reorder or remove any digits in s. 

You may return the valid IP addresses in any order.

Example 1:
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:
Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


Constraints:
1 <= s.length <= 20
s consists of digits only.
*/

using namespace std;

#include <vector>
#include <iostream>
#include <string>

namespace {

    class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            if (s.length() < 4) {
                return res_;
            }

            dfs(s, 0, 0, "");
            return res_;
        }

    private:
        void dfs(string& s, int index, int num_dot, string tracked) {
            if (num_dot == 3) {
                // check if the rest part is valid
                if (validIP(s.substr(index))) {
                    // append the last part to tracked string
                    res_.push_back(tracked + "." + s.substr(index));
                }
                return;
            }

            for (int i = index + 1; i < s.size(); i++) {
                // pruning
                if (!validIP(s.substr(index, i - index)))
                    continue;

                if (num_dot == 0) {
                    // if we haven't put any dot, update the tracked string without adding dot
                    dfs(s, i, num_dot + 1, tracked + s.substr(index, i - index));
                }
                else {
                    dfs(s, i, num_dot + 1, tracked + "." + s.substr(index, i - index));
                }
            }
        }

        bool validIP(string s) {
            if (s.size() > 3 || s.size() < 1)
                return false;

            // if there is leading zeros
            if (s.size() > 1 && s[0] == '0')
                return false;

            // if the value is larger than 255
            if (stoi(s) > 255)
                return false;

            return true;
        }

    private:
        vector<string> res_;
    };


} // namespace

void testRestoreIPAddresses() {
    /*
        Input: s = "25525511135", Output: ["255.255.11.135","255.255.111.35"]
    */
    string s = "25525511135";
    vector<string> result = Solution().restoreIpAddresses(s);
}
