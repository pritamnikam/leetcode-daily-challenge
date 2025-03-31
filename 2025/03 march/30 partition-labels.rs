// 763. partition-labels
// https://leetcode.com/problems/partition-labels

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let end_positions = s.bytes()
                                .enumerate()
                                .fold(
                                    [0; 26],
                                    |mut eps, (i, b)| {
                                        eps[(b-b'a') as usize] = i;
                                        eps
                                    }
                                );

        let mut count = 0;
        let mut end = 0;

        s.bytes()
            .enumerate()
            .flat_map(|(i, b)| {
                count += 1;
                end = end.max(end_positions[(b - b'a') as usize]);
                (i == end).then(|| std::mem::replace(&mut count, 0))
            })
            .collect()
    }
}
