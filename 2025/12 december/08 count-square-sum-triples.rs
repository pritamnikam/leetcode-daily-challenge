// count-square-sum-triples
// https://leetcode.com/problems/count-square-sum-triples

impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut answer = 0;

        // enumerate a & b
        for a in 1..=n {
            for b in 1..=n {
                // determine if it meets the requirments
                let c = ((a * a + b * b) as f64).sqrt().floor() as i32;
                if (c <= n) && ((c * c) == (a * a + b * b)) {
                    answer += 1;
                }
            }
        }
        answer
    }
}
