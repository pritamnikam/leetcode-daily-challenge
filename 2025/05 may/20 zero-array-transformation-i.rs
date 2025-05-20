// 3355. zero-array-transformation-i
// https://leetcode.com/problems/zero-array-transformation-i


impl Solution {
    pub fn is_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
	// Initialize a delta (difference) array with one extra space for prefix sum technique
        let mut delta_array = vec![0; nums.len() + 1];

        // Apply each query range as a difference array operation
        for query in queries {
            let left = query[0] as usize;
            let right = query[1] as usize;

            // Mark the beginning of the increment
            delta_array[left] += 1;

            // Mark the end+1 to cancel the effect after the range
            delta_array[right + 1] -= 1;
        }

        // Reconstruct the actual operation counts using prefix sums
        let mut operation_counts = Vec::with_capacity(delta_array.len());
        let mut current_operations = 0;

        for delta in delta_array {
            current_operations += delta;
            operation_counts.push(current_operations);
        }

        // Check if each number in `nums` can be reduced to zero or below
        for i in 0..nums.len() {
            if operation_counts[i] < nums[i] {
                // Not enough operations applied to reduce nums[i] to 0
                return false;
            }
        }

        // All elements can be reduced to zero or below
        true
    }
}
