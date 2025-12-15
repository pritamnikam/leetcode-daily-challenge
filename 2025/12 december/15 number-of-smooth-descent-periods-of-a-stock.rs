// number-of-smooth-descent-periods-of-a-stock
// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

impl Solution {
    pub fn get_descent_periods(prices: Vec<i32>) -> i64 {
        let n = prices.len();
        let mut result: i64 = 1;
        let mut prev: i32 = 1;

        for i in 1..n {
            if prices[i] == prices[i-1]-1 {
                prev += 1;
            } else {
                prev = 1;
            }
            result += prev as i64;
        }
        result
    }
}
