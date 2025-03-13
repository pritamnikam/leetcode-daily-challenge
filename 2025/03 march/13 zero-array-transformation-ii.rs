// 3356. zero-array-transformation-ii
// https://leetcode.com/problems/zero-array-transformation-ii

impl Solution {
    pub fn min_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        let n = nums.len();
        let max = queries.len() as i32;

        let check = |target: i32| -> bool {
            let freq = queries
              .iter()
              .take(target as usize)
              .fold(vec![0; n + 1], |mut f, q| {
                f[q[0] as usize] += q[2];
                f[q[1] as usize + 1] -= q[2];
                f
              });

            nums
              .iter()
              .enumerate()
              .scan(0, |decr, (i, &n)| {
                *decr += freq[i];
                Some(*decr >= n)
              })
              .all(|r| r)
        };
        let step = |left: i32, right: i32| {
            if left > right {
                None
            } else {
                let mid = left + (right - left) / 2;
                if check(mid) {
                    Some((left, mid - 1, mid, true))
                } else {
                    Some((mid + 1, right, mid, false))
                }
            }
        };
        std::iter::successors(step(0, max), |&(left, right, mid, ok)| {
            step(left, right)
        })
        .filter(|&(_, _, _, ok)| ok)
        .map(|(_, _, mid, _)| mid)
        .min()
        .unwrap_or(-1)
    }
}
