// 2094. finding-3-digit-even-numbers
// https://leetcode.com/problems/finding-3-digit-even-numbers

impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        // Count available digits
        let mut available = [0; 10];
        for digit in digits {
            available[digit as usize] += 1;
        }

        let mut result = Vec::new();

        // Check all 3-digit even numbers
        for num in (100..1000).step_by(2) {
            let needed = Self::count_digits(num);

            // Check if 'num' can be formed using 'available' digits
            if needed.iter()
                .zip(available.iter())
                .all(|(&need, &have)| need <= have)
            {
                result.push(num);
            }
        }

        result
    }

    // Helper: counts how many times each digit appears in a number
    fn count_digits(mut num: i32) -> [i32; 10] {
        let mut freq = [0; 10];
        while num > 0 {
            freq[(num % 10) as usize] += 1;
            num /= 10;
        }
        freq
    }
}
