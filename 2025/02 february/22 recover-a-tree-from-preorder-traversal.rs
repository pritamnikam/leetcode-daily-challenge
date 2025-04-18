// 1028. recover-a-tree-from-preorder-traversal
// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
    pub fn recover_from_preorder(traversal: String) -> Option<Rc<RefCell<TreeNode>>> {

        let mut parser = traversal.bytes().peekable();
        let mut stack = Vec::new();

        let mut value = 0;
        while let Some(b) = parser.next_if(u8::is_ascii_digit) {
            value = value * 10 + (b - b'0') as i32;
        }
        
        stack.push(
            (0, Rc::new(RefCell::new(TreeNode::new(value))))
        );

        loop {
            let mut depth = 0;

            while let Some(_) = parser.next_if_eq(&b'-') {
                depth += 1;
            }

            let mut value = 0;
            while let Some(b) = parser.next_if(u8::is_ascii_digit) {
                value = value * 10 + (b - b'0') as i32;
            }

            if value == 0 {
                return Some(stack.swap_remove(0).1)
            }

            loop {
                let last = stack.pop().unwrap();
                if last.0 < depth {
                    let new_node = Rc::new(RefCell::new(TreeNode::new(value)));
                    let mut last_borrow = last.1.borrow_mut();

                    if last_borrow.left.is_some() {
                        last_borrow.right = Some(new_node.clone());
                    } else {
                        last_borrow.left = Some(new_node.clone());
                    }

                    drop(last_borrow);
                    stack.push(last);
                    stack.push((depth, new_node));
                    break;
                }
            }
        }
    }
}
