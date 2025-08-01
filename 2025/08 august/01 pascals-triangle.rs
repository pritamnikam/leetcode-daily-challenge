// 118. pascals-triangle
// https://leetcode.com/problems/pascals-triangle
use std::iter::once;

impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        (2..=num_rows).fold(vec![vec![1]], |mut acc, _| {
            acc.push(once(1)
                .chain(acc.last().unwrap().windows(2).map(|n| n.iter().copied().sum()))
                .chain(once(1))
                .collect::<Vec<_>>());
            acc
        })
    }

  pub fn generate2(num_rows: i32) -> Vec<Vec<i32>> {
    let mut rez: Vec<Vec<i32>> = Vec::with_capacity(num_rows as usize);
    for i in 0..num_rows as usize {
      let mut row = vec![1; i + 1];
      for j in 1..i {
        row[j] = rez[i-1][j] + rez[i-1][j-1];
      }
      rez.push(row);
    }
    rez
}
