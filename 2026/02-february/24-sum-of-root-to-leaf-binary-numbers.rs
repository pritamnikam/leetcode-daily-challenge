// sum-of-root-to-leaf-binary-numbers
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn recu(maybe_node: &Option<Rc<RefCell<TreeNode>>>, prefix: i32) -> i32 {
            match maybe_node {
                None => {return 0}
                Some(is_node) => {
                    let node = is_node.borrow();
                    let mut res = prefix * 2 + node.val;
                    let l = recu(&node.left, res);
                    let r = recu(&node.right, res);
                    if l > 0 || r > 0 {res = l + r}
                    return res;
                }
            }
        }
        recu(&root, 0)
    }
}
