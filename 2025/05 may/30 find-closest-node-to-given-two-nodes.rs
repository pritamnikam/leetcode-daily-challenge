// 2359. find-closest-node-to-given-two-nodes
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes

impl Solution {
    pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
        fn get_distances(edges: &Vec<i32>, start: usize) -> Vec<i32> {
            let mut dist = vec![-1; edges.len()];
            let mut d = 0;
            let mut current = start;
            while current != usize::MAX && dist[current] == -1 {
                dist[current] = d;
                d += 1;
                let next = edges[current];
                if next == -1 {
                    break;
                }
                current = next as usize;
            }
            dist
        }

        let dist1 = get_distances(&edges, node1 as usize);
        let dist2 = get_distances(&edges, node2 as usize);
        let mut result = -1;
        let mut min_distance = i32::MAX;

        for i in 0..edges.len() {
            if dist1[i] != -1 && dist2[i] != -1 {
                let max_dist = dist1[i].max(dist2[i]);
                if max_dist < min_distance {
                    min_distance = max_dist;
                    result = i as i32;
                }
            }
        }
        result
    }
}
