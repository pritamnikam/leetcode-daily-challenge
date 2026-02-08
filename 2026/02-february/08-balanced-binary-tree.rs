// balanced-binary-tree
// https://leetcode.com/problems/balanced-binary-tree

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
use std::cmp;

impl Solution {
    pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::dfs(&root) != -1
    }

    fn dfs(
        node: &Option<Rc<RefCell<TreeNode>>>
    ) -> i32 {
        match node {
            None => 0,
            Some(n) => {
                let n = n.borrow();
                let left = Self::dfs(&n.left);
                if left == -1 {
                    return -1;
                }

                let right = Self::dfs(&n.right);
                if right == -1 {
                    return -1;
                }

                if (left - right).abs() > 1 {
                    return -1;
                }

                1 + cmp::max(left, right)
            } 
        }
    }
}
