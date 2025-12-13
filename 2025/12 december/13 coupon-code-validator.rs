// coupon-code-validator
// https://leetcode.com/problems/coupon-code-validator

use std::mem::take;
impl Solution {
    pub fn validate_coupons(code: Vec<String>, business_line: Vec<String>, is_active: Vec<bool>) -> Vec<String> {
        let n = code.len();
        let mut code = code;

        // lambda: is_valid
        let is_valid = |i: &usize| {
            is_active[*i] &&
            !code[*i].is_empty() &&
            code[*i].chars().all(|c| c.is_ascii_alphanumeric() || c == '_') &&
            matches!(business_line[*i].as_str(), 
                        "electronics" | "grocery" | "pharmacy" | "restaurant")
        };

        // filter out valid & sort
        let mut valid_idxs = (0..n).filter(is_valid).collect::<Vec<_>>();
        valid_idxs.sort_by_key(|&i| (&business_line[i], &code[i]));
        valid_idxs.into_iter().map(|i| take(&mut code[i])).collect()
    }
}
