// maximum-level-sum-of-a-binary-tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut result = vec![0, 0]; // Record every level's node's value sum
        let mut queue = Vec::new(); // Use Breadth-First Search, iterate every level
        let mut new_queue = Vec::new(); // Record the next level

        // First put the first level
        queue.push(
            (root.unwrap(), 1)
        );

        while let Some((node, level)) = queue.pop() {
            result[level] += node.borrow().val;

            if let Some(left) = node.borrow().left.clone() {
                new_queue.push(
                    (left, level + 1)
                );
            }

            if let Some(right) = node.borrow().right.clone() {
                new_queue.push(
                    (right, level + 1)
                );
            }

            if queue.is_empty() {
                std::mem::swap(&mut queue, &mut new_queue);
                result.push(0);
            }
        }

        // Record the max index
        let mut max_index = 1;
        for i in 1..result.len() - 1 {
            if result[i] > result[max_index] {
                max_index = i;
            }
        }
        max_index as i32
    }
}
