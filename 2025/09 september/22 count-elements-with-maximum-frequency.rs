// count-elements-with-maximum-frequency
// https://leetcode.com/problems/count-elements-with-maximum-frequency

impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut frequency_counts = [0i32; 101];
        let mut value_counts = [0; 101];
        let mut max_frequency = 0;

        for n in nums {
            let n = n as usize;
            frequency_counts[value_counts[n]] -= value_counts[n] as i32;
            value_counts[n] += 1;
            frequency_counts[value_counts[n]] += value_counts[n] as i32;
            max_frequency = max_frequency.max(value_counts[n]);
        }

        frequency_counts[max_frequency]
    }
}
