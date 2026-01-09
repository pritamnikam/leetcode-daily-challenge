// smallest-subtree-with-all-the-deepest-nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

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
    pub fn subtree_with_all_deepest(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
                fn dfs(
            node: Option<Rc<RefCell<TreeNode>>>
        ) -> (i32, Option<Rc<RefCell<TreeNode>>>) {
            match node {
                None => (0, None),
                Some(n) => {
                    let left = n.borrow().left.clone();
                    let right = n.borrow().right.clone();
                    let (ld, ln) = dfs(left);
                    let (rd, rn) = dfs(right);
                    if ld > rd {
                        (ld + 1, ln)
                    } else if rd > ld {
                        (rd + 1, rn)
                    } else {
                        (ld + 1, Some(n))
                    }
                }
            }
        }

        dfs(root).1
    }
}
