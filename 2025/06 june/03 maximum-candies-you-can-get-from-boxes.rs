// 1298. maximum-candies-you-can-get-from-boxes
// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes

use std::collections::VecDeque;

impl Solution {
    pub fn max_candies(
        status: Vec<i32>, 
        candies: Vec<i32>, 
        keys: Vec<Vec<i32>>, 
        contained_boxes: Vec<Vec<i32>>, 
        initial_boxes: Vec<i32>
    ) -> i32 {

        let n = status.len();
        let mut can_open = vec![false; n];
        let mut has_box = vec![false; n];
        let mut used = vec![false; n];

        for i in 0..n {
            can_open[i] = (status[i] == 1);
        }
        let mut q = VecDeque::new();
        let mut ans = 0;
        for box_id in initial_boxes {
            has_box[box_id as usize] = true;
            if can_open[box_id as usize] {
                q.push_back(box_id);
                used[box_id as usize] = true;
                ans += candies[box_id as usize];
            }
        }

        while let Some(big_box) = q.pop_front() {
            for &key in &keys[big_box as usize] {
                can_open[key as usize] = true;
                if !used[key as usize] && has_box[key as usize] {
                    q.push_back(key);
                    used[key as usize] = true;
                    ans += candies[key as usize];
                }
            }
            for &box_id in &contained_boxes[big_box as usize] {
                has_box[box_id as usize] = true;
                if !used[box_id as usize] && can_open[box_id as usize] {
                    q.push_back(box_id);
                    used[box_id as usize] = true;
                    ans += candies[box_id as usize];
                }
            }
        }

        ans
    }
}
