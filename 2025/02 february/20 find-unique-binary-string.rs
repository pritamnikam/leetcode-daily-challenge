// find-unique-binary-string
// https://leetcode.com/problems/find-unique-binary-string

impl Solution {
    pub fn find_different_binary_string(nums: Vec<String>) -> String {
        let n = nums.len();
        let mut seen = vec![false; 1 << n];
        for v in nums {
            seen[u32::from_str_radix(&v, 2).unwrap() as usize] = true;
        }

        for i in 0..seen.len() {
            if !seen[i] {
                return String::from(format!("{:0width$b}", i, width=n));
            }
        }
        "".to_string()
    }
}
