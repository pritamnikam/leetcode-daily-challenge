// find-the-minimum-amount-of-time-to-brew-potions
// https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions


impl Solution {
    pub fn min_time(skill: Vec<i32>, mana: Vec<i32>) -> i64 {
        let mut delay = 0;
        let w = skill.len();
        let mut wizard_end_time = vec![0; w];

        for &potion in &mana {
            let mut time = 0;
            let mut potion_delay = 0;

            for i in 0..w {
                potion_delay = potion_delay.max(wizard_end_time[i] - time);
                time += (skill[i] * potion) as i64;
                wizard_end_time[i] = time;
            }

            delay += potion_delay;
        }

        *wizard_end_time.last().unwrap() + delay
    }
}
