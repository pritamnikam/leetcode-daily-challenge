// 2685. count-the-number-of-complete-components
// https://leetcode.com/problems/count-the-number-of-complete-components

use std::collections::HashSet;
use std::cmp::Ordering;

struct DSU {
    parents: Vec<i32>,
    ranks: Vec<i32>
}

impl DSU {
    fn new(n: i32) -> Self {
        Self {
            parents: (0..n).collect(),
            ranks: vec![0; n as usize]
        }
    }

    fn find(&mut self, a: i32) -> i32 {
        if self.parents[a as usize] != a {
            self.parents[a as usize] = self.find(self.parents[a as usize]);
        }
        self.parents[a as usize]
    }

    fn union(&mut self, mut a: i32, mut b: i32) {
        a = self.find(a);
        b = self.find(b);

        if a == b {
            return;
        }

        match self.ranks[a as usize].cmp(&self.ranks[b as usize]) {
            Ordering::Less => self.parents[a as usize] = b,
            Ordering::Greater => self.parents[b as usize] = a,
            Ordering::Equal => {
                self.ranks[a as usize] += 1;
                self.parents[b as usize] = a;
            }
        }
    }
}

impl Solution {
    pub fn count_complete_components(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut dsu = DSU::new(n);
        let mut set = HashSet::new();
        for e in edges {
            dsu.union(e[0], e[1]);

            set.insert((e[0], e[1]));
            set.insert((e[1], e[0]));
        }

        let mut groups = vec![Vec::new(); n as usize];
        for i in 0..n {
            groups[dsu.find(i) as usize].push(i);
        }

        let mut ans = 0;

        for i in 0..groups.len() {
            let mut valid = true;
            'outer: for j in 0..groups[i].len() {
                for k in j + 1..groups[i].len() {
                    if !set.contains(&(groups[i][j], groups[i][k])) {
                        valid = false;
                        break 'outer;
                    }
                }
            }

            if !groups[i].is_empty() && valid {
                ans += 1;
            }
        }
        ans
    }
}
