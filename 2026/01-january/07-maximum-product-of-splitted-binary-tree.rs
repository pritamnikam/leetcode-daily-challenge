// maximum-product-of-splitted-binary-tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

// Intuition
// To do these type of questions ask yourself, what info comming from
// subtree will benifit the solving. (Like min of subtree, max of subtree). In this case, sum of subtree

// Approach:
// Consider the tree as
// R1: root
// T1: subtree(1)
// T2 : subtree(2)
// We have to find (max(sum(T1 + R1) * sum(T2)))

// where sum(T2) = total_sum - sum(T1);


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


fn get_total_sum(root: &Option<Rc<RefCell<TreeNode>>>) -> i64 {
    if let Some(node) = root {
        let _n = node.borrow();
        let leftsum = match _n.left {
            Some(ref subnode) => get_total_sum(&Some(Rc::clone(subnode))),
            None => 0,
        };
        let righsum = match _n.right {
            Some(ref subnode) => get_total_sum(&Some(Rc::clone(subnode))),
            None => 0,
        };
        return leftsum + righsum + _n.val as i64;
    }
    0
}

fn get_sum_under(root: &Option<Rc<RefCell<TreeNode>>>, total_sum: i64, result: &mut i64) -> i64 {
    if let Some(node) = root {
        let _n = node.borrow();
        let leftsum = match _n.left {
            Some(ref subnode) => get_sum_under(&Some(Rc::clone(subnode)), total_sum, result),
            None => 0,
        };
        let rightsum = match _n.right {
            Some(ref subnode) => get_sum_under(&Some(Rc::clone(subnode)), total_sum, result),
            None => 0,
        };
        let sum = leftsum + rightsum + _n.val as i64;
        *result = i64::max(*result, (total_sum - sum) * sum);
        return sum;
    }
    0
}

impl Solution {
    pub fn max_product(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let total_sum = get_total_sum(&root);
        let mut result = 0;

        get_sum_under(&root, total_sum, &mut result);
        let modulo = i64::pow(10, 9) + 7;
        (result % modulo) as i32
    }
}
