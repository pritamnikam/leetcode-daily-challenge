// 889. construct-binary-tree-from-preorder-and-postorder-traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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

type OptNode = Option<Rc<RefCell<TreeNode>>>;

impl Solution {
    pub fn construct_from_pre_post(preorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::construct(
            &preorder[..],
            &postorder[..]
        )
    }

    fn construct(
        pre: &[i32],
        post: &[i32]
    ) -> OptNode {
        match pre.len() {
            0 => None,
            1 => Some(Rc::new(RefCell::new(TreeNode::new(pre[0])))),
            n => {
                let root = pre[0];

                let first = pre[1];
                let idx = post.iter().position(|&x| x == first).unwrap();

                let mut out = TreeNode::new(root);
                out.left = Self::construct(&pre[1..=idx + 1], &post[0..=idx]);
                out.right = Self::construct(&pre[idx + 2..], &post[idx+1..n - 1]);
            
                Some(Rc::new(RefCell::new(out)))
            }
        }
    }
}
