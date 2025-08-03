// 2106. maximum-fruits-harvested-after-at-most-k-steps
// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps

impl Solution {
    pub fn max_total_fruits(fruits: Vec<Vec<i32>>, start_pos: i32, k: i32) -> i32 {
        
        fn min_steps(
            left: i32,
            right: i32,
            start: i32
        ) -> i32 {
        
            let go_left = (start - left).abs() + (right - left);
            let go_right = (start - right).abs() + (right - left);
            go_left.min(go_right)
        }


        let (mut left, mut sum, mut max_fruits) = (0, 0, 0);

        for right in 0..fruits.len() {
            sum += fruits[right][1];

            while ((left <= right) 
                    && (min_steps(fruits[left][0], fruits[right][0], start_pos) > k)) {
                sum -= fruits[left][1];
                left += 1;
            }

            max_fruits = max_fruits.max(sum);
        }
        max_fruits
    }
}
