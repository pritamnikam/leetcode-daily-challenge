// 2864. Maximum Odd Binary Number
// https://leetcode.com/problems/maximum-odd-binary-number/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // Create char array
        const int N = s.length();
        char* arr = new char[N + 1];
        strcpy(arr, s.c_str());

        // init 2 pointers
        int left = 0, right = N - 1;

        while (left <= right) {
            // increment left if '1'
            if (arr[left] == '1') left++;

            // decrement right if '0'
            if (arr[right] == '0') right--;

            // swap if neither pointer can be iterated
            if (left <= right && arr[left] == '0' && arr[right] == '1') {
                arr[left] = '1';
                arr[right] = '0';
            }
        }

        arr[left - 1] = '0';
        arr[N - 1] = '1';
        return arr;
    }
};
