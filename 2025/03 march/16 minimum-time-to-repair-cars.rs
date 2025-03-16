// 2594. minimum-time-to-repair-cars
// https://leetcode.com/problems/minimum-time-to-repair-cars

impl Solution {
    pub fn repair_cars(ranks: Vec<i32>, cars: i32) -> i64 {
        let mut left = 1i64;
        let mut right = (*ranks.iter().max().unwrap() as i64) 
                            * (i64::pow(cars as i64/ranks.len() as i64+1,2));
        while left < right {
            let mid = (left+right) / 2;
            let sum = ranks.iter().fold(
                0,
                |sum,rank| sum + (f64::sqrt((mid / *rank as i64) as f64) as i64)
            );
            if sum >= cars as i64 {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        left
    }
}
