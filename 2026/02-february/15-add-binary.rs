// add-binary
// https://leetcode.com/problems/add-binary

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        // Rust's primitive integers (like u128) have size limits.
        // For arbitrary precision, a crate like `num-bigint` would be used.
        // The following shows the concept with u128.
        let num_a = u128::from_str_radix(&a, 2).unwrap();
        let num_b = u128::from_str_radix(&b, 2).unwrap();
        format!("{:b}", num_a + num_b)
    }
}
