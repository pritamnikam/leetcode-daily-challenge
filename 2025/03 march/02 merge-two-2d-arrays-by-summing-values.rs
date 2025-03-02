// 2570. merge-two-2d-arrays-by-summing-values
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        nums1
            .into_iter()
            .chain(nums2)
            .map(|v| (v[0], v[1]))
            .fold(std::collections::BTreeMap::new(), |mut tree, (k, v)| {
                tree
                    .entry(k)
                    .and_modify(|x| *x += v)
                    .or_insert(v);
                tree
            })
            .into_iter()
            .map(|(a, b)| vec![a, b])
            .collect()
    }
}
