// 2566. maximum-difference-by-remapping-a-digit
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

impl Solution {
    pub fn min_max_difference(num: i32) -> i32 {
        // Convert the number to a string for easy character manipulation
        let s = num.to_string();
        
        // Clone the string to use for finding the minimum value
        let mut t = s.clone();
        
        // Find the first position where the character is not '9'
        let pos = s.chars().position(|c| c != '9');
        
        // Clone the original string to use for finding the maximum value
        let mut max = s.clone();

        // If a non-'9' character is found, replace all occurrences of it with '9'
        if let Some(pos) = pos {
            let a = s.chars().nth(pos).unwrap(); // Get the first non-'9' character
            max = s.replace(a, "9"); // Replace all occurrences of this character with '9'
        }

        // Get the first character of the original number string
        let b = t.chars().next().unwrap();
        
        // Replace all occurrences of the first character with '0' to get the minimum value
        let min = t.replace(b, "0");

        // Convert the modified strings back to integers and return their difference
        max.parse::<i32>().unwrap() - min.parse::<i32>().unwrap()
    }
}
