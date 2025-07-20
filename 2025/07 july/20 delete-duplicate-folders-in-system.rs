// 1948. delete-duplicate-folders-in-system
// https://leetcode.com/problems/delete-duplicate-folders-in-system
use std::collections::{BTreeMap, HashMap};

struct Node {
    children: BTreeMap<String, Node>,
    deleted: bool,
}

impl Node {
    fn new() -> Self {
        Node { children: BTreeMap::new(), deleted: false }
    }
}


    fn encode<'a>(
        node: &'a mut Node,
        groups: &mut HashMap<String, Vec<*mut Node>>,
    ) -> String {
        if node.children.is_empty() {
            return "()".into();
        }
        let mut parts: Vec<String> = node
            .children
            .iter_mut()
            .map(|(name, child)| format!("{}{}", name, encode(child, groups)))
            .collect();
        parts.sort();
        let sign = format!("({})", parts.join(""));
        groups.entry(sign.clone())
            .or_default()
            .push(node as *mut _);
        sign
    }

    fn collect(node: &Node, path: &mut Vec<String>, res: &mut Vec<Vec<String>>) {
        for (name, child) in &node.children {
            if child.deleted { continue; }
            path.push(name.clone());
            res.push(path.clone());
            collect(child, path, res);
            path.pop();
        }
    }

impl Solution {
    pub fn delete_duplicate_folder(paths: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let mut root = Node::new();
        // Build trie
        for path in paths {
            let mut cur = &mut root;
            for name in path {
                cur = cur.children.entry(name).or_insert_with(Node::new);
            }
        }
        // Encode subtrees
        let mut groups: HashMap<String, Vec<*mut Node>> = HashMap::new();
        encode(&mut root, &mut groups);
        // Mark duplicates
        for nodes in groups.values() {
            if nodes.len() > 1 {
                for &ptr in nodes {
                    unsafe { (*ptr).deleted = true; }
                }
            }
        }
        // Collect remaining paths
        let mut result = Vec::new();
        collect(&root, &mut Vec::new(), &mut result);
        result   
    }


}
