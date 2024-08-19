// 650. 2 Keys Keyboard
// https://leetcode.com/problems/2-keys-keyboard


/*
This problem is equivalent to taking the prime factorization of n,
for each prime factor f, add f to the sum.

e.g. n = 12, 12 = 2 * 2 * 3
'A' -> 'AA' (takes 2 steps [COPY, PASTE]),
'AA' -> 'AAAA' (takes 2 steps [COPY, PASTE]),
'AAAA' -> 'AAAAAAAAAAAA' (takes 3 steps [COPY, PASTE, PASTE])
*/

class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        int k = 2;
        
        // prime factorization algo
        while (n >= k) {
            if (n % k == 0) {
                n /= k;
                count += k;
            } else {
                k++;
            }
        }
        return count;
    }
};
