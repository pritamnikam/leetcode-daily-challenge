// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> gr = findGrestesToRight(height);
        vector<int> gl = findGrestesToLeft(height);

        int waterTrapped = 0;
        for (int i = 0; i < height.size(); i++) {
            waterTrapped += min(gr[i], gl[i]) - height[i];
        }

        return waterTrapped;
    }

private:
    vector<int> findGrestesToLeft(vector<int>& height) {
        vector<int> gl(height.size());
        gl[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
            if (gl[i - 1] > height[i]) {
                gl[i] = gl[i - 1];
            }
            else {
                gl[i] = height[i];
            }
        }

        return gl;
    }

    vector<int> findGrestesToRight(vector<int>& height) {
        vector<int> gr(height.size());
        gr[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            if (gr[i + 1] > height[i]) {
                gr[i] = gr[i + 1];
            }
            else {
                gr[i] = height[i];
            }
        }

        return gr;
    }
};
