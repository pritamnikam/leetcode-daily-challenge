// 1726. tuple-with-same-product
// https://leetcode.com/problems/tuple-with-same-product/

use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let n = nums.len();

        let mut product_count: HashMap<i32, i32> = HashMap::new();
        for i in 0..n {
            for j in i+1..n {
                let product = nums[i] * nums[j];
                *product_count.entry(product).or_insert(0) += 1;
            }
        }

        4 * product_count.values().map(|count| count * (count - 1)).sum::<i32>()
    }
}
