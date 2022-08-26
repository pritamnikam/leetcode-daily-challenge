/*
383. Ransom Note
https://leetcode.com/problems/ransom-note/

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.



Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true


Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace {
	class Solution {
	public:
		bool canConstruct(string ransomNote, string magazine) {
			unordered_map<char, int> magazinCharFreq; // O(k) -> k = 26 i.e. constant, O(1)
			for (char ch : magazine) {
				magazinCharFreq[ch]++;
			}


			for (char ch : ransomNote) {
				if (magazinCharFreq.count(ch) == 0)
					return false;

				magazinCharFreq[ch]--;
			}

			return true;
		}
	};
}