// 2872. maximum-number-of-k-divisible-components
// https://leetcode.com/problems/maximum-number-of-k-divisible-components

impl Solution {
    pub fn max_k_divisible_components(
        n: i32,
        edges: Vec<Vec<i32>>,
        values: Vec<i32>,
        k: i32
    ) -> i32 {
        let n = n as usize;
        let mut g = vec![Vec::new(); n];

        for e in edges {
            let a = e[0] as usize;
            let b = e[1] as usize;
            g[a].push(b);
            g[b].push(a);
        }

        let mut ans = 0;

        fn dfs(
            u: usize,
            p: usize,
            g: &Vec<Vec<usize>>,
            values: &Vec<i32>,
            k: i32,
            ans: &mut i32
        ) -> i64 {
            let mut sum = values[u] as i64;

            for &v in &g[u] {
                if v == p { continue; }
                sum += dfs(v, u, g, values, k, ans);
            }

            if sum % (k as i64) == 0 {
                *ans += 1;
                return 0;
            }
            sum
        }

        dfs(0, usize::MAX, &g, &values, k, &mut ans);
        ans
    }
}
