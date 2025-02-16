// 1718. construct-the-lexicographically-largest-valid-sequence
// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence

impl Solution {

  fn dfs(arr: &mut Vec<i32>, p: usize) -> Vec<i32> {
    if p == arr.len() {
      return arr.to_vec();
    }
    if arr[p] != 0 {
      return Self::dfs(arr, p + 1);
    }

    for num in (1 .. arr.len() / 2 + 2).rev() {
      if arr.contains(&(num as i32)) { 
        continue;
      }

      if num == 1 {
        arr[p] = 1;
        let res = Self::dfs(arr, p + 1);
        if !res.is_empty() {
          return res;
        }
        arr[p] = 0;
      } else if p + num < arr.len() && arr[p + num] == 0 {
        arr[p] = num as i32;
        arr[p + num] = num as i32;
        let res = Self::dfs(arr, p + 1);
        if !res.is_empty() {
          return res;
        }
        arr[p] = 0 as i32;
        arr[p + num] = 0 as i32;
      }
    }

    return Vec::new();
  }

  pub fn construct_distanced_sequence(n: i32) -> Vec<i32> {
    let mut arr = vec![0; (2 * n - 1) as usize];
    return Self::dfs(&mut arr, 0);
  }
}
