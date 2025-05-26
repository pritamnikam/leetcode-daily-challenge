// 1857. largest-color-value-in-a-directed-graph
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph

impl Solution {
    pub fn largest_path_value(colors: String, edges: Vec<Vec<i32>>) -> i32 {
        largest_path_value(colors, edges)
    }
}


const CYCLE_FOUND: i32 = -1;

#[derive(Debug, Copy, Clone, Eq, PartialEq)]
enum State {
    HasCycle,
    Processed,
}

pub fn largest_path_value(colors: impl AsRef<[u8]>, edges: Vec<Vec<i32>>) -> i32 {
    let colors = colors.as_ref();
    assert!(colors.len() > 0);

    let mut cache = vec![[0; 256]; colors.len()];
    let mut visited = vec![false; colors.len()];

    let mut graph = vec![vec![]; colors.len()];
    for edge in edges.iter() {
        graph[edge[0] as usize].push(edge[1] as usize);
    }

    for node in 0..graph.len() {
        if dfs(&mut visited, &mut cache, &graph, &colors, node) == State::HasCycle {
            return CYCLE_FOUND;
        }
    }

    cache.into_iter().map(|x| x).flatten().max().unwrap_or(0)
}

fn dfs(
    visited: &mut [bool],
    cache: &mut [[i32; 256]],
    graph: &[Vec<usize>],
    colors: &[u8],
    node: usize,
) -> State {
    // Check if we have visited this node through some path in the DFS
    if visited[node] {
        return State::HasCycle;
    }
    visited[node] = true;

    // Process the node, only if we have not processed it before
    if cache[node][colors[node] as usize] <= 0 {
        for next in graph[node].iter().copied() {
            if dfs(visited, cache, graph, colors, next) == State::HasCycle {
                return State::HasCycle;
            }

            // We use only the 'a'-'z' range due to the problem constraints
            for idx in b'a' as usize..b'z' as usize + 1 {
                cache[node][idx] = cache[node][idx].max(cache[next][idx]);
            }
        }

        // permanently remember that we have processed this node
        cache[node][colors[node] as usize] += 1;
    }

    // Remove, the "visited flag, because we might reach this node
    // through another parent, without forming a cycle
    visited[node] = false;
    State::Processed
}
