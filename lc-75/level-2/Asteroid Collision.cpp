/*
735. Asteroid Collision
https://leetcode.com/problems/asteroid-collision/

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents 
its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, 
the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.


Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

*/

using namespace std;

#include <vector>
#include <iostream>


namespace {
    class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> s; // use vector to simulate stack.
            for (int i = 0; i < asteroids.size(); i++) {
                // a[i] is positive star or a[i] is negative star and there is no positive on stack
                if (asteroids[i] > 0 || s.empty() || s.back() < 0)
                    s.push_back(asteroids[i]);

                // a[i] is negative star and stack top is positive star
                else if (s.back() <= -asteroids[i]) {
                    // only positive star on stack top get destroyed, stay on i to check more on stack.
                    if (s.back() < -asteroids[i]) i--;

                    // destroy positive star on the frontier;
                    s.pop_back();
                } // else : positive on stack bigger, negative star destroyed.
            }
            return s;
        }
    };
}
