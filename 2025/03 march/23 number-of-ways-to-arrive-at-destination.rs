// number-of-ways-to-arrive-at-destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

use std::collections::BinaryHeap;
use std::cmp::Reverse;

const MOD: i32 = 1_000_000_007;

impl Solution {
    pub fn count_paths(n: i32, roads: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut graph = vec![vec![]; n];

        // build graph
        for road in &roads {
            let (u,v,time) = (road[0] as usize, road[1] as usize, road[2]);
            graph[u].push((v, time));
            graph[v].push((u, time));
        }

        // Dijkstra
        let mut dist = vec![i64::MAX; n];
        let mut ways = vec![0; n];

        dist[0] = 0;
        ways[0] = 1;

        let mut pq = BinaryHeap::new();
        pq.push(Reverse((0,0)));

        while let Some(Reverse((cur_dist, node))) = pq.pop() {
            if cur_dist > dist[node] {
                continue;
            }

            for &(neighbor, time) in &graph[node] {
                let new_dist = cur_dist + time as i64;

                if new_dist < dist[neighbor] {
                    dist[neighbor] = new_dist;
                    ways[neighbor] = ways[node];
                    pq.push(Reverse((new_dist, neighbor)));
                } else if new_dist == dist[neighbor] {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            } 
        }

        ways[n-1]
    }
}
