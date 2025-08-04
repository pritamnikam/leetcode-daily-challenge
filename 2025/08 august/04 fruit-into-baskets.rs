// fruit-into-baskets
// https://leetcode.com/problems/fruit-into-baskets

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let (mut last, mut second_last) = (-1, -1);
        let (mut last_count, mut curr, mut max_fruits) = (0, 0, 0);

        for &f in fruits.iter() {
            if f == last || f == second_last {
                curr += 1;
            } else {
                curr = last_count + 1;
            }

            if f == last {
                last_count += 1;
            } else {
                last_count = 1;
                second_last = last;
                last = f;
            }

            max_fruits = max_fruits.max(curr);
        }

        max_fruits
    }
}
