// 3477. fruits-into-baskets-ii
// https://leetcode.com/problems/fruits-into-baskets-ii

impl Solution {
    pub fn num_of_unplaced_fruits(fruits: Vec<i32>, mut baskets: Vec<i32>) -> i32 {
        let mut count = 0;
        let n = baskets.len();

        for fruit in fruits {
            let mut unset = 1;
            for i in 0..n {
                if fruit <= baskets[i] {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            count += unset;
        }
        count
    }
}
