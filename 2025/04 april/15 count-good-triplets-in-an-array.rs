// count-good-triplets-in-an-array
// https://leetcode.com/problems/count-good-triplets-in-an-array

struct FenwickTree {
    tree: Vec<i32>,
}

impl Solution {
    pub fn good_triplets(nums1: Vec<i32>, nums2: Vec<i32>) -> i64 {
        let n = nums1.len();

        // Map value → index in nums2
        let mut pos2 = vec![0; n];
        for (i, v) in nums2.into_iter().enumerate() {
            pos2[v as usize] = i;
        }

        let mut sum_tree = FenwickTree::new(n);

        nums1.into_iter().enumerate().map(|(i, v)| {
            let j = pos2[v as usize]; // Corresponding index in nums2
            // Count values before i in nums1 that are also before j in nums2
            let left_count = sum_tree.query(j) as usize;
            // Count values after i in nums1 that are also after j in nums2
            let right_count = n - j - 1 - (i - left_count);
            // Mark position j as seen
            sum_tree.add(j, 1);

            (left_count * right_count) as i64
        }).sum()
    }
}

impl FenwickTree {
    // Initializes a Fenwick Tree with the given size.
    fn new(size: usize) -> Self {
        let n = 1 << (1 + Self::msb(size));
        Self { tree: vec![0; n + 1] }
    }

    // Adds a value to the Fenwick Tree at a specific index.
    fn add(&mut self, mut index: usize, value: i32) {
        index += 1;
        while index < self.tree.len() {
            self.tree[index] += value;
            index += index & (!index + 1);
        }
    }

    // Queries the cumulative sum up to a specific index.
    fn query(&self, mut index: usize) -> i32 {
        let mut sum = 0;
        index += 1;
        while index > 0 {
            sum += self.tree[index];
            index &= index - 1;
        }
        sum
    }

    fn msb(mut n: usize) -> usize {
        let mut pos: usize = 0;
        while n > 0 {
            n >>= 1;
            pos += 1;
        }
        pos.saturating_sub(1)
    }
}
