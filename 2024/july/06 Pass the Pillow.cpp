// 2582. Pass the Pillow
// https://leetcode.com/problems/pass-the-pillow

class Solution {
public:
    int passThePillow(int n, int time) {
        int chunk = time / (n - 1);
        return (chunk % 2 == 0) 
                ? (time % (n - 1) + 1) 
                : (n - time %(n-1));
    }
};
