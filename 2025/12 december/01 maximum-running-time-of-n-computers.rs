// 2141. maximum-running-time-of-n-computers
// https://leetcode.com/problems/maximum-running-time-of-n-computers

impl Solution {
    pub fn max_run_time(n: i32, batteries: Vec<i32>) -> i64 {
        let mut total: i64 = batteries.iter().map(|&x| x as i64).sum();
        let mut batteries = batteries;
        let mut n = n;
        batteries.sort();

        for &b in batteries.iter().rev() {
            if (b as i64) > total / (n as i64) {
                total -= b as i64;
                n -= 1;
            } else {
                break;
            }
        }

        total / (n as i64)
    }
}
