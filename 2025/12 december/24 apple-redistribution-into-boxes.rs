// apple-redistribution-into-boxes
// https://leetcode.com/problems/apple-redistribution-into-boxes

impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, capacity: Vec<i32>) -> i32 {
        let mut sum: i32 = apple.iter().sum();
        let mut sorted_capacity = capacity.clone();

        sorted_capacity.sort_by(|a,b| b.cmp(a));

        let mut need = 0;
        while sum > 0 {
            sum -= sorted_capacity[need as usize];
            need += 1;
        }
        need
    }
}
