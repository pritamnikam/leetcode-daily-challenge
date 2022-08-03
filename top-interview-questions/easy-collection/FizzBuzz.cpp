/*
Fizz Buzz

Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.


Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]


Constraints:

1 <= n <= 104

*/

using namespace std;

#include <string>
#include <vector>

class Solution {
    const string kFizz = "Fizz";
    const string kBuzz = "Buzz";
    const string kFizzBuzz = "FizzBuzz";

public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            // answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
            if (i % 3 == 0 && i % 5 == 0)
                result.emplace_back(kFizzBuzz);

            // answer[i] == "Fizz" if i is divisible by 3.
            else if (i % 3 == 0)
                result.emplace_back(kFizz);

            // answer[i] == "Buzz" if i is divisible by 5.
            else if (i % 5 == 0)
                result.emplace_back(kBuzz);
            else
                result.emplace_back(to_string(i));
        }

        return result;
    }
};