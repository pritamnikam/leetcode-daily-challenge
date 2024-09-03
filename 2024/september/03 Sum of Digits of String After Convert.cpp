// 1945. Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    int getLucky(string s, int k) {
        // convert string to integer by summing digit values
        int currentNumber = 0;
        for (char ch: s) {
            int position = ch -'a' +1;
            while (position > 0) {
                currentNumber += position % 10;
                position /= 10;
            }
        }

        // apply digit sum transformations k-1 times
        for (int i = 1; i < k; i++) {
            int digitSum = 0;
            while (currentNumber > 0) {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }

            currentNumber = digitSum;
        }

        return currentNumber;
    }
};
