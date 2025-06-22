// 2138. divide-a-string-into-groups-of-size-k
// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k

impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let mut res = Vec::new(); // grouped string
        let n = s.len();
        let mut curr = 0; // starting index of each group
        // split string
        while curr < n {
            let end = (curr + k as usize).min(n);
            res.push(s[curr..end].to_string());
            curr += k as usize;
        }
        // try to fill in the last group
        if let Some(last) = res.last_mut() {
            if last.len() < k as usize {
                *last += &fill.to_string().repeat(k as usize - last.len());
            }
        }
        res
    }
}
