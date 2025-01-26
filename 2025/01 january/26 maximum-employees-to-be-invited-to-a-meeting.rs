// maximum-employees-to-be-invited-to-a-meeting
// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/

use std::collections::{HashMap, VecDeque};
/// # `maximum_invitations`
/// Finds the maximum number of employees that can be invited to a meeting
/// where each employee must sit next to their favorite person.
///
/// ## Algorithm
/// 1. Uses topological sort to process leaf nodes and compute chain lengths
/// 2. Identifies cycles and mutual pairs in the remaining graph
/// 3. Returns the maximum of either:
///    - Largest cycle length
///    - Sum of mutual pairs with their attached chains
///
/// ## Arguments
/// * `favorite` - A vector where favorite[i] represents employee i's favorite person
///
/// ## Returns
/// * The maximum number of employees that can be invited
impl Solution {
    pub fn maximum_invitations(favorite: Vec<i32>) -> i32 {
        let n = favorite.len();
        let mut visited = vec![false; n];
      
        // Maximum chain length ending at each node
        let mut to_leaf = vec![0; n];
        let mut in_degree = vec![0; n];

        // Calculate in-degrees for each node
        for &fav in favorite.iter() {
            in_degree[fav as usize] += 1;
        }

        // Process leaf nodes using topological sort
        let mut queue = VecDeque::new();
        for (i, &deg) in in_degree.iter().enumerate() {
            if deg == 0 {
                queue.push_back(i);
                visited[i] = true;
            }
        }

        // Calculate maximum chain lengths
        while let Some(node) = queue.pop_front() {
            let next = favorite[node] as usize;
            to_leaf[next] = to_leaf[next].max(1 + to_leaf[node]);
            in_degree[next] -= 1;
            if in_degree[next] == 0 {
                visited[next] = true;
                queue.push_back(next);
            }
        }

        // Process remaining nodes to find cycles
        let (mut max_cycle, mut pairs_with_chains) = (0, 0);
        for i in 0..n {
            if !visited[i] {
                let mut len = 0;
                let mut curr = i;

                // Find cycle length
                while !visited[curr] {
                    visited[curr] = true;
                    len += 1;
                    curr = favorite[curr] as usize;
                }

                // Handle mutual pairs (cycles of length 2) specially
                if len == 2 {
                    pairs_with_chains += 2 + to_leaf[i] + to_leaf[favorite[i] as usize];
                } else {
                    max_cycle = max_cycle.max(len);
                }
            }
        }

        max_cycle.max(pairs_with_chains)
    }
}
