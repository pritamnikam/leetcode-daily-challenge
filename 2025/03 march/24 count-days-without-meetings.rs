// 3169. count-days-without-meetings
// https://leetcode.com/problems/count-days-without-meetings

impl Solution {
    pub fn count_days(days: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        meetings.sort_unstable();
        let (mut work_until, mut res) = (0,0);
        for v in meetings {
            if v[0] > work_until {
                res += v[0] - work_until - 1;
            }
            work_until = work_until.max(v[1]);
        }

        res + days - work_until
    }
}
