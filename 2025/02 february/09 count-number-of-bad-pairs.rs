// 2364. count-number-of-bad-pairs
// https://leetcode.com/problems/count-number-of-bad-pairs

use std::collections::HashMap;

fn count_bad_pairs(nums: Vec<i32>) -> i64 {
    let mut total_pairs = (nums.len() as i64) * (nums.len() as i64 - 1) / 2;
    let mut good_pairs = 0;
    let mut freq_map = HashMap::new();

    for (i, &num) in nums.iter().enumerate() {
        let key = num - (i as i32);
        if let Some(&count) = freq_map.get(&key) {
            good_pairs += count;
        }
        *freq_map.entry(key).or_insert(0) += 1;
    }

    total_pairs - good_pairs
}

fn main() {
    let nums1 = vec![4,1,3,3];
    println!("{}", count_bad_pairs(nums1)); // Output: 5

    let nums2 = vec![1,2,3,4,5];
    println!("{}", count_bad_pairs(nums2)); // Output: 0
}
