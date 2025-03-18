//
//

impl Solution {
    pub fn divide_array(nums: Vec<i32>) -> bool {
        nums.into_iter()
            .fold(std::collections::HashMap::new(), |mut freq_map, num| {
                freq_map.entry(num).and_modify(|v| *v += 1).or_insert(1);
                freq_map
            })
            .values()
            .all(|v| v & 1 == 0)
    }
}
