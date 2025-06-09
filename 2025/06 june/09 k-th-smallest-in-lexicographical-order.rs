// 440. k-th-smallest-in-lexicographical-order
// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order

impl Solution {
    pub fn find_kth_number(n: i32, k: i32) -> i32 {
        fn count_prefix(n: i64, prefix: i64) -> i32 {
            let mut curr = prefix;
            let mut next = prefix + 1;
            let mut count = 0;
            while curr <= n {
                count += ((n + 1).min(next) - curr) as i32;
                curr *= 10;
                next *= 10;
            }
            count
        }

        let mut p = 1;
        let mut k = k - 1; 
        let n = n as i64;

        while k > 0 {
            let count = count_prefix(n, p as i64);
            if k >= count {
                p += 1;
                k -= count;
            } else {
                p *= 10;
                k -= 1;
            }
        }

        p
    }
}
