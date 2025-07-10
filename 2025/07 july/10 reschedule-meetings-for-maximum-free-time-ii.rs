// 3440. reschedule-meetings-for-maximum-free-time-ii
// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii

impl Solution {
    pub fn max_free_time(event_time: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        let n = start_time.len();

        // `q[i]` will mark if event `i` can be skipped (i.e., its duration is less than or equal to surrounding free time)
        let mut q = vec![false; n];

        // `t1` tracks max available time before each event (from left to right)
        // `t2` tracks max available time after each event (from right to left)
        let mut t1 = 0;
        let mut t2 = 0;

        for i in 0..n {
            // If current event's duration fits into the left free window, mark it as skippable
            if end_time[i] - start_time[i] <= t1 {
                q[i] = true;
            }

            // Update available time before the current event
            t1 = t1.max(start_time[i] - if i == 0 { 0 } else { end_time[i - 1] });

            // `j` is the mirrored index from the end (for right-to-left pass)
            let j = n - i - 1;

            // If current event's duration fits into the right free window, mark it as skippable
            if end_time[j] - start_time[j] <= t2 {
                q[j] = true;
            }

            // Update available time after the current event
            t2 = t2.max(
                if i == 0 {
                    event_time // space after the last event
                } else {
                    start_time[n - i] // time from end of current to start of next (backward)
                } - end_time[j],
            );
        }

        let mut res = 0;

        for i in 0..n {
            // Calculate free window between previous and next events
            let left = if i == 0 { 0 } else { end_time[i - 1] };
            let right = if i == n - 1 { event_time } else { start_time[i + 1] };

            if q[i] {
                // If the event can be skipped, the entire window is considered free
                res = res.max(right - left);
            } else {
                // Otherwise, subtract current event's duration from the window
                res = res.max(right - left - (end_time[i] - start_time[i]));
            }
        }

        res
    }
}
