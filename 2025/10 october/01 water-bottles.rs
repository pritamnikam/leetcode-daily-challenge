// 1518. water-bottles/
// https://leetcode.com/problems/water-bottles/

impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut consumed_bottles = 0;
        let mut num_bottles = num_bottles;

        while num_bottles >= num_exchange {
            let mut k = num_bottles / num_exchange;
            consumed_bottles += num_exchange * k;
            num_bottles -= num_exchange * k;

            num_bottles += k;
        }

        consumed_bottles + num_bottles
    }
}
