// find-the-punishment-number-of-an-integer
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

impl Solution {
    pub fn punishment_number(n: i32) -> i32 {
        let range = 1..=n;
        range.into_iter()
            .filter(
                Self::valid
            ).map(|a| a * a)
            .sum()
    }

    fn valid(s: &i32) -> bool {
        let mut temp = s * s;
        let mut digits = vec![];
        while temp > 0 {
            digits.push(temp % 10);
            temp = temp / 10;
        }
        digits.reverse();
        Self::helper(&digits, 0, 0, s)
    }

    fn helper(d:&Vec<i32>, i: usize, sum: i32, target: &i32) -> bool {
        if i == d.len() {
            return sum == *target;
        }

        let mut partition = 0;
        let mut j = i;
        loop {
            if j == d.len() {
                return false;
            }

            partition = partition * 10 + d[j];
            if Self::helper(d, j + 1, sum + partition, target) {
                return true;
            }

            j += 1;
        }
    }
}
