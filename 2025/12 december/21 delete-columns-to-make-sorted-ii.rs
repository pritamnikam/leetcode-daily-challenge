// delete-columns-to-make-sorted-ii
// https://leetcode.com/problems/delete-columns-to-make-sorted-ii

impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let m = strs.len();
        let n = strs.first().map_or(0, |s| s.len());

        // Set of "certainly in order" rows.
        let mut inorder = 0_u128; 
        let mut count   = 0;

        for col in 0..n {
            let mut new_inorder = 0_u128;

            for row in 1..m {
                if inorder & 1 << row != 0 { 
                    continue; 
                }
                let prev = strs[row - 1].as_bytes();
                let curr = strs[row    ].as_bytes();

                if prev[col] > curr[col] {
                    count += 1;
                    new_inorder = 0;
                    break;
                } 
                if prev[col] < curr[col] {
                    new_inorder |= 1 << row;
                }
            }
            inorder |= new_inorder;
        }
        count
    }
}
