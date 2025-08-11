// 2438. range-product-queries-of-powers
// https://leetcode.com/problems/range-product-queries-of-powers

impl Solution {
    pub fn product_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        const MOD: i64 = 1_000_000_007;
        let mut bins = Vec::new();
        let mut n = n;
        let mut rep = 1;
        // decompose the integer n into a list of powers of 2 based on its binary representation.
        while n > 0 {
            if n % 2 == 1 {
                bins.push(rep);
            }
            n /= 2;
            rep *= 2;
        }

        // If the k-th binary digit (starting from the least significant bit) is 1, then the 
        // power 2^k contributes to the decomposition of n.
        let m = bins.len();
        let mut results = vec![vec![0; m]; m];
        for i in 0..m {
            let mut cur: i64 = 1;
            for j in i..m {
                cur = (cur * bins[j]) % MOD;
                results[i][j] = cur as i32;
            }
        }

        queries.iter()
            .map(
                |query| 
                results[query[0] as usize][query[1] as usize]
            )
            .collect()
    }
}
