// 684. redundant-connection
// https://leetcode.com/problems/redundant-connection/
//

struct DSU {
    parent: Vec<usize>,
    rank: Vec<usize>,
}

impl DSU {
    fn new(n: usize) -> Self {
        DSU {
            parent: (0..=n).collect(),
            rank: vec![1; n + 1],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    fn union(&mut self, x: usize, y: usize) -> bool {
        let root_x = self.find(x);
        let root_y = self.find(y);
        if root_x == root_y {
            return false;
        }
        if self.rank[root_x] > self.rank[root_y] {
            self.parent[root_y] = root_x;
        } else if self.rank[root_x] < self.rank[root_y] {
            self.parent[root_x] = root_y;
        } else {
            self.parent[root_y] = root_x;
            self.rank[root_x] += 1;
        }
        true
    }
}
impl Solution {
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut dsu = DSU::new(edges.len());
    
        for edge in edges {
            let (u, v) = (edge[0] as usize, edge[1] as usize);
            if !dsu.union(u, v) {
                return edge; // The first edge that forms a cycle
            }
        }
        vec![]

    }
}
