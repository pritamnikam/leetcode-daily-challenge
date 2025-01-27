// course-schedule-iv
// https://leetcode.com/problems/course-schedule-iv/

impl Solution {
    pub fn check_if_prerequisite(num_courses: i32, prerequisites: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let n = num_courses as usize;
        let mut reachable = vec![vec![false; n]; n];

        // Step 1: Build the reachability matrix
        for pre in &prerequisites {
            let u = pre[0] as usize;
            let v = pre[1] as usize;
            reachable[u][v] = true;
        }

        // Step 2: Floyd-Warshall Algorithm to compute transitive closure
        for k in 0..n {
            for i in 0..n {
                for j in 0..n {
                    if reachable[i][k] && reachable[k][j] {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        // Step 3: Answer queries in O(1) time
        queries.iter().map(|q| reachable[q[0] as usize][q[1] as usize]).collect()
    }
}
