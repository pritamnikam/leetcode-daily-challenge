//
//

fn max_score(s: String) -> i32 {

  let chars: Vec<char> = s.chars().collect();
  let n = chars.len();

  // compute the total number of ones in the string
  let total_ones = chars.iter().filter(|&&c| c == '1').count() as i32; 

  let mut max_score = 0;
  let mut left_zeros = 0;
  let mut right_ones = 0;

  for i in 0..n - 1 {
    if chars[i] == '0' {
      left_zeros += 1;
    } else {
      right_ones -= 1;
    }

    let score = left_zeros + right_ones;
    max_score = max_score.max(score);
  }
  max_score
}
