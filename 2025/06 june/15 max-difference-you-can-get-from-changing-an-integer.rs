// 1432. max-difference-you-can-get-from-changing-an-integer
// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer

impl Solution {
    pub fn max_diff(num: i32) -> i32 {

        // Closure to replace all occurrences of digit `x` with digit `y` in the number
        let change = |x: i32, y: i32| -> String {
            num.to_string() // Convert the number to a string
                .chars() // Iterate over the characters in the string
                .map(|digit| 
                    if digit.to_digit(10).unwrap() as i32 == x { 
                        // If the digit matches `x`, replace it with `y`
                        (y as u8 + b'0') as char 
                    } else { 
                        // Otherwise, keep it unchanged
                        digit 
                    }
                )
                .collect() // Collect the modified characters back into a string
        };

        // Initialize min_num and max_num with the original number
        let (mut min_num, mut max_num) = (num, num);

        // Iterate over all digits (0-9) as possible replacements
        for x in 0..10 {
            for y in 0..10 {
                
                let res = change(x, y); // Get the modified number as a string
                
                // Ensure the modified number does not start with '0', avoiding invalid leading zeros
                if res.chars().nth(0).unwrap() != '0' {
                    let res_i: i32 = res.parse().unwrap(); // Convert the string back to an integer
                    min_num = min_num.min(res_i); // Update min_num if a lower value is found
                    max_num = max_num.max(res_i); // Update max_num if a higher value is found
                }
            }
        }

        // Return the difference between the maximum and minimum possible values
        max_num - min_num
    }
}
