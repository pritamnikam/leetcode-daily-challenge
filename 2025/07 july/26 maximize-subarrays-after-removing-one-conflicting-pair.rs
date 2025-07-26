// 3480. maximize-subarrays-after-removing-one-conflicting-pair
// https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/

impl Solution {
    pub fn max_subarrays(n: i32, conflicting_pairs: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut b_min1 = vec![i32::MAX; n + 1];
        let mut b_min2 = vec![i32::MAX; n + 1];
        for pair in conflicting_pairs {
            let a = pair[0].min(pair[1]) as usize;
            let b = pair[0].max(pair[1]);
            if b_min1[a] > b {
                b_min2[a] = b_min1[a];
                b_min1[a] = b;
            } else if b_min2[a] > b {
                b_min2[a] = b;
            }
        }
        let mut res: i64 = 0;
        let mut ib1 = n;
        let mut b2 = i32::MAX;
        let mut del_count = vec![0i64; n + 1];
        for i in (1..=n).rev() {
            if b_min1[ib1] > b_min1[i] {
                b2 = b2.min(b_min1[ib1]);
                ib1 = i;
            } else {
                b2 = b2.min(b_min1[i]);
            }
            res += (b_min1[ib1].min((n + 1) as i32) - i as i32) as i64;
            del_count[ib1] += (b2.min(b_min2[ib1]).min((n + 1) as i32) - b_min1[ib1].min((n + 1) as i32)) as i64;
        }
        res + *del_count.iter().max().unwrap()
    }
}
