// 1792. maximum-average-pass-ratio
// https://leetcode.com/problems/maximum-average-pass-ratio

impl Solution {
	pub fn max_average_ratio(classes: Vec<Vec<i32>>, ext: i32) -> f64 {
		let mut bh = std::collections::BinaryHeap::new();
		let prob = |a, b| (a as f64) / (b as f64);
		let dif = |a, b| prob(a + 1, b + 1) - prob(a, b);
		for cl in classes {
			let (ps, tot) = (cl[0], cl[1]);
			bh.push(((dif(ps, tot) * 1e9) as i64, ps, tot));
		}
		for _ in 0..ext {
			if let Some((_, ps, tot)) = bh.pop() {
				bh.push(((dif(ps + 1, tot + 1) * 1e9) as i64, ps + 1, tot + 1));
			}
		}
		bh.iter().map(|&(_, ps, tot)| prob(ps, tot)).sum::<f64>() / bh.len() as f64
	}
}
