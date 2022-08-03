/*
Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0


Constraints:
0 <= n <= 5 * 106

*/

#if 0
Sieve of Eratosthenes

The steps involved to separate the prime numbers from 1 to 100 are as follows :

Step 1 : First write all the natural numbers from 1 to 100, row - wise and column - wise.
Step 2 : Put a cross over 1, as it is neither a prime number nor a composite.
Step 3 : Now, encircle the number 2 (which is a prime number) and cross all the multiples of 2, such as 4, 6, 8, 10, 12, and so on.Since all the multiples of 2 are composite.
Step 4 : Next, encircle the number 3, and put a cross over all the multiples of 3, such as 6, 9, 15, 21, etc.Since apart from 3 all its multiples are composite.
Step 5 : Again, encircle the number 5 (since it has only two factors), and put a cross over all the multiples of 5.
Step 6 : Now encircle 7 and cross all the multiples of 7
Step 7 : Encircle 11 and cross all the multiples of 11
Step 8 : Continue the process unless all the numbers are either encircled or crossed.

Therefore, we have concluded that all the encircled numbers are prime numbersand all the crossed numbers are composite numbers.So, the prime numbers from 1 to 100 are :

    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, and 97
#endif


class Solution {
    bool isPrimeNumbers(int n) {
        // Corner case
        if (n <= 1) return false;

        // Check from 2 to square root of n
        for (int i = 2; i <= sqrt(n); ++i)
            if (n % i == 0) return false;

        return true;
    }

    vector<int> getAllPrimeNumbers(int n) {
        vector<int> primes;
        for (int i = 2; i < n; ++i) {
            if (isPrimeNumbers(i)) {
                // cout << i << ", ";
                primes.emplace_back(i);
            }
        }

        return primes;
    }

    public:
#if 0
        // Time limit exception
        int countPrimes(int n) {
            vector<int> primes = getAllPrimeNumbers(n);
            return primes.size();
        }
#endif

        // Using Sieve of Eratosthenes
        int countPrimes(int n) {
            if (n == 0) return 0;

            vector<bool> primes(n, true);
            int count = 0;

            primes[0] = false;
            primes[1] = false;

            for (int i = 2; i < n; i++) {
                if (primes[i] == true) {
                    count++;
                    for (int j = 2; j * i < n; j++) {
                        primes[j * i] = false;
                    }
                }
            }

            return count;
        }

};