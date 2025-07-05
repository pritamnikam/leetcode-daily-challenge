// 1394. find-lucky-integer-in-an-array
// https://leetcode.com/problems/find-lucky-integer-in-an-array

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        arr.into_iter()
            .fold([0; 500], |mut f, num| {
                f[num as usize - 1] += 1;
                f
            })
            .into_iter()
            .enumerate()
            .rfind(|(i, v)|  *v - *i as i32 == 1)
            .map_or(-1, |(_, v)| v)
    }
}
