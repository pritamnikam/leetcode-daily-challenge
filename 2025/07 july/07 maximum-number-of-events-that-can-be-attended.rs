// 1353. maximum-number-of-events-that-can-be-attended
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended


use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn max_events(events: Vec<Vec<i32>>) -> i32 {
        let mut events = events;

        // Sort events by their start day (earliest to latest)
        events.sort_by(|a, b| a[0].cmp(&b[0]));

        // Determine the latest day across all events to limit iteration
        let max_day = events.iter().map(|e| e[1]).max().unwrap_or(0);

        // Min-heap to store event end days for active events
        // Reverse is used to simulate min-heap since BinaryHeap is max-heap by default
        let mut pq = BinaryHeap::new();

        let mut ans = 0;  // Count of events attended
        let mut j = 0;    // Pointer to iterate through sorted events

        // Iterate day by day from 1 to max_day
        for day in 1..=max_day {
            // Add all events that start today or earlier into the heap
            // These are potential events we could attend today
            while j < events.len() && events[j][0] <= day {
                pq.push(Reverse(events[j][1])); // Push event end day
                j += 1;
            }

            // Remove all events from the heap that have already ended (i.e., can't be attended)
            while let Some(&Reverse(end)) = pq.peek() {
                if end < day {
                    pq.pop(); // Event has expired before today
                } else {
                    break; // Remaining events are still valid
                }
            }

            // Attend the event that ends the earliest (greedy choice)
            // This maximizes room for future events
            if let Some(Reverse(_)) = pq.pop() {
                ans += 1;
            }
        }

        ans
    }
}
