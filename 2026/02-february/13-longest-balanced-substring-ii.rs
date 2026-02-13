// longest-balanced-substring-ii
// https://leetcode.com/problems/longest-balanced-substring-ii/
use std::collections::HashMap;

impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let mut result = Self::longest_one(&s);
        for w in ['a', 'b', 'c'] {
            result = result.max(
                Self::longest_two(&s, w)
            );
        }
        result = result.max(
            Self::longest_three(&s)
        );
        result
    }


  fn longest_one(s: &str) -> i32 {
    let mut res = 1;
    let mut prev = '\0';
    let mut curr = 0;

    for c in s.chars() {
      if c == prev {
        curr += 1;
        res = res.max(curr);
      } else {
        curr = 1;
        prev = c;
      }
    }
    res
  }

  fn longest_two(s: &str, wrong_c: char) -> i32 {
    let mut res = 0;
    let mut mapping: HashMap<i32, i32> = HashMap::new();
    mapping.insert(0, -1);
    let mut delta = 0;
    let chars: Vec<char> = "abc".chars().filter(|&c| c != wrong_c).collect();
    let char_a = chars[0];
    let char_b = chars[1];

    for (i, c) in s.chars().enumerate() {
      let i = i as i32;
      if c == wrong_c {
        mapping.clear();
        mapping.insert(0, i);
        delta = 0;
      } else {
        if c == char_a {
          delta += 1;
        } else if c == char_b {
          delta -= 1;
        }

        if let Some(&start) = mapping.get(&delta) {
          res = res.max(i - start);
        } else {
          mapping.insert(delta, i);
        }
      }
    }
    res
  }
    fn longest_three(s: &str) -> i32 {
    let mut mapping: HashMap<(i32, i32), i32> = HashMap::new();
    mapping.insert((0, 0), -1);
    let mut res = 0;
    let mut cnt_a = 0;
    let mut cnt_b = 0;
    let mut cnt_c = 0;

    for (i, c) in s.chars().enumerate() {
      let i = i as i32;
      match c {
        'a' => cnt_a += 1,
        'b' => cnt_b += 1,
        'c' => cnt_c += 1,
        _ => {}
      }

      let ba = cnt_b - cnt_a;
      let ca = cnt_c - cnt_a;

      if let Some(&start) = mapping.get(&(ba, ca)) {
        res = res.max(i - start);
      } else {
        mapping.insert((ba, ca), i);
      }
    }

    res
      }
}
