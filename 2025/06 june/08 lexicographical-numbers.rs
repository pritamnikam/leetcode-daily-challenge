// 386. lexicographical-numbers
// https://leetcode.com/problems/lexicographical-numbers

impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        // Helper DFS function
        // x: current number being built (acts as a prefix)
        // n_ref: reference to the upper limit n
        // v: mutable reference to the result vector
        fn dfs(x: i32, n_ref: &i32, v: &mut Vec<i32>) {
            // Try appending digits 0 through 9 to the current number x
            for i in 0..10 {
                let tmp = x * 10 + i; // Form the new number

                // Pruning conditions:
                // 1. If tmp exceeds the limit n, stop exploring this path.
                //    Any further digits appended or larger i will also exceed n.
                // 2. If tmp is 0 (occurs if x=0 and i=0), skip it.
                //    Numbers are from 1 to n.
                if tmp > *n_ref || tmp == 0 {
                    continue; 
                }

                // If tmp is a valid number (1 <= tmp <= n):
                v.push(tmp);       // Add it to the result vector
                dfs(tmp, n_ref, v); // Recursively explore numbers with tmp as prefix
            } 
        }

        // Initialize the result vector with capacity n for efficiency
        let mut v = Vec::with_capacity(n as usize);
        
        // Start DFS. Passing 0 as the initial x allows generation of
        // single-digit numbers (1-9) correctly in the first level of recursion.
        // For x=0, tmp becomes 0*10 + i = i.
        // The tmp==0 check handles the i=0 case.
        // So, for i=1 to 9, if i <= n, it's added, and dfs(i, ...) is called.
        dfs(0, &n, &mut v);
        
        v // Return the lexicographically sorted list of numbers
    }
}
