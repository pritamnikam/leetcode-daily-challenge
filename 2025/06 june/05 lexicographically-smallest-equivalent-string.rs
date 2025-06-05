// 1061. lexicographically-smallest-equivalent-string
// https://leetcode.com/problems/lexicographically-smallest-equivalent-string

impl Solution {
    pub fn smallest_equivalent_string(s1: String, s2: String, base_str: String) -> String {
        let mut roots = (0..27).collect::<Vec<u8>>();
        for (mut a, mut b) in s1.bytes().zip(s2.bytes()) {
            a = Self::get_root((a - b'a') as usize, &mut roots);
            b = Self::get_root((b - b'a') as usize, &mut roots);
            match a.cmp(&b) {
                std::cmp::Ordering::Less => roots[b as usize] = a,
                std::cmp::Ordering::Equal => continue,
                std::cmp::Ordering::Greater => roots[a as usize] = b,
            }
        }
        base_str
            .bytes()
            .map(|b| (Self::get_root((b - b'a') as usize, &mut roots) + b'a') as char)
            .collect()
    }

    fn get_root(x: usize, roots: &mut [u8]) -> u8 {
        if roots[x] == x as u8 {
            return x as u8;
        }
        roots[x] = Self::get_root(roots[x] as usize, roots);
        roots[x]
    }
}
