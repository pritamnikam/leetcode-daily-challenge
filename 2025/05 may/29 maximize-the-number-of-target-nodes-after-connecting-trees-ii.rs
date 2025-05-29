// 3373. maximize-the-number-of-target-nodes-after-connecting-trees-ii
// https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii

impl Solution {
    pub fn max_target_nodes(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>) -> Vec<i32> {
        // Get the Union-Find parent and size arrays for both edge sets
        let (mut parent1, size1) = Self::build_union_find(&edges1);
        let (mut parent2, size2) = Self::build_union_find(&edges2);

        // Find the size of the connected component containing node 0 in the second graph
        let root = Self::find(0, &mut parent2);
        let group_size = size2[root];

        // Consider the larger group size out of two complementary groups
        let total_nodes = size2.len() as i32 / 2; // Half because we doubled the nodes
        let larger_group = group_size.max(total_nodes - group_size);

        // Prepare the result: for each node in the first graph, add its component size + larger_group
        let mut result = Vec::with_capacity(edges1.len() + 1);
        for i in 0..=edges1.len() {
            let root = Self::find(i, &mut parent1);
            result.push(size1[root] + larger_group);
        }

        result
    }

    // Builds a bipartite-aware union-find structure from the given edge list
    fn build_union_find(edges: &Vec<Vec<i32>>) -> (Vec<usize>, Vec<i32>) {
        let n = edges.len() + 1;
        let mut parent: Vec<usize> = (0..n * 2).collect(); // Each node duplicated (for bipartite logic)
        let mut size = vec![0; n * 2];

        // Initially, each original node has size 1 (ignore the duplicated set)
        for i in 0..n {
            size[i] = 1;
        }

        // Union each edge a–b as bipartite: a ↔ b+n and a+n ↔ b
        for edge in edges {
            let a = edge[0] as usize;
            let b = edge[1] as usize;
            Self::union(a, b + n, &mut parent, &mut size); // a is opposite group of b
            Self::union(a + n, b, &mut parent, &mut size); // a+n is in same group as b
        }

        (parent, size)
    }

    // Find with path compression
    fn find(node: usize, parent: &mut Vec<usize>) -> usize {
        if parent[node] != node {
            parent[node] = Self::find(parent[node], parent); // Compress path
        }
        parent[node]
    }

    // Union by size: smaller root joins the larger
    fn union(a: usize, b: usize, parent: &mut Vec<usize>, size: &mut Vec<i32>) {
        let mut root_a = Self::find(a, parent);
        let mut root_b = Self::find(b, parent);

        if root_a != root_b {
            // Ensure larger size becomes the root
            if size[root_a] < size[root_b] {
                std::mem::swap(&mut root_a, &mut root_b);
            }
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
        }
    }
}
