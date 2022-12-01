/*
1704. Determine if String Halves Are Alike
https://leetcode.com/problems/determine-if-string-halves-are-alike/

You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). 
Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.



Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.


Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.

*/

using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace {
    class Solution {
        const unordered_set<char> vowels{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        bool isVowel(char ch) {
            return vowels.count(ch) != 0;
        }

    public:
        bool halvesAreAlike(string s) {
            int vowelDiff = 0,
                mid = size(s) / 2;

            // vowels difference b/w 1st & 2nd half
            for (int i = 0; i < mid; i++)
                vowelDiff += isVowel(s[i]) - isVowel(s[mid + i]);
            return !vowelDiff;
        }
    };
} // namespace

void testDetermineIfStringHalvesAreAlike() {
    /*
        Input: s = "book" | Output: true
    */

    cout << "Determine if String Halves Are Alike: " << Solution().halvesAreAlike("book") << endl;

    /*
        Input: s = "textbook" | Output: false
    */
    cout << "Determine if String Halves Are Alike: " << Solution().halvesAreAlike("textbook") << endl;

    /*
        Input: s = "tootabook" | Output: true
    */
    cout << "Determine if String Halves Are Alike: " << Solution().halvesAreAlike("tootabook") << endl;


    /*
       Input: s = "AbCdEfGh" | Output: true
   */
    cout << "Determine if String Halves Are Alike: " << Solution().halvesAreAlike("AbCdEfGh") << endl;
}
