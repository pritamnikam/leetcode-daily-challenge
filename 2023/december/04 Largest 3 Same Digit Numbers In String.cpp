// 2264. Largest 3 Same Digit Numbers In String
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/

class Solution {
public:
    string largestGoodInteger(string num) {
        int result = -1;
        for (int i = 0; i + 2 < num.length(); i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                result = std::max(result, num[i] - '0');
            }
        }
        return (result == -1) ? "" : std::string(3, '0' + result);
    }
};
