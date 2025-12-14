// number-of-ways-to-divide-a-long-corridor
// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor

impl Solution {
    pub fn number_of_ways(corridor: String) -> i32 {
        // Use fold to accumulate while iterating over 'corridor'
        // The fold starts with (0, 0, 1) and updates it for each char

        corridor.chars().fold((0, 0, 1), |state, thing| {
            match thing {
                // If the character is 'S', update the based on current state
                'S' => (state.1, state.2, state.1),
                // For any other character, update the last element of the tuple
                _ => (state.0, state.1, (state.2 + state.0) % 1_000_000_007),
            }
        }).0
    
    }
}
