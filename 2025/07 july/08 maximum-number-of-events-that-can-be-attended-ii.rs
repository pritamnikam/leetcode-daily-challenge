// 1751. maximum-number-of-events-that-can-be-attended-ii
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii

impl Solution {
    pub fn max_value(events: Vec<Vec<i32>>, k: i32) -> i32 {
        let k = k as usize;
        let mut dp = vec![vec![0; k + 1]; events.len() + 1];
        let mut events: Vec<_> = events
            .into_iter()
            .map(|event| *event.first_chunk::<3>().unwrap())
            .collect();
        events.sort_unstable();

        for (i, event) in events.iter().take(events.len()).enumerate().rev() {
            let [_, end, value] = *event;
            let next_event = events.partition_point(|target_event| end >= target_event[0]);

            for attended_events in 0..k {
                dp[i][attended_events + 1] =
                    dp[i][attended_events + 1].max(value + dp[next_event][attended_events]);
                dp[i][attended_events + 1] =
                    dp[i][attended_events + 1].max(dp[i + 1][attended_events + 1]);
            }
        }

        dp[0][k]
    }
}
