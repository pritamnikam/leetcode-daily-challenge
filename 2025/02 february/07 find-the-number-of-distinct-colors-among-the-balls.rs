// 3160. find-the-number-of-distinct-colors-among-the-balls
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls

use std::collections::HashMap;

impl Solution {
    pub fn query_results(limit: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ball_color: HashMap<i32, i32> = HashMap::new();
        let mut color_count: HashMap<i32, i32> = HashMap::new();
        let mut result: Vec<i32> = Vec::with_capacity(queries.len());

        for i in queries {
            let x = i[0];
            let y = i[1];

            // If the ball is already colored, decrement the count of its current color
            if let Some(&old_color) = ball_color.get(&x) {
                if let Some(count) = color_count.get_mut(&old_color) {
                    *count -= 1;
                    if *count == 0 {
                        color_count.remove(&old_color);
                    }
                }
            }

            // Set the new color for the ball
            ball_color.insert(x, y);

            // Increment the count of the new color
            *color_count.entry(y).or_insert(0) += 1;

            // Add the current number of unique colors to the result
            result.push(color_count.len() as i32);
        }

        result
    }
}
