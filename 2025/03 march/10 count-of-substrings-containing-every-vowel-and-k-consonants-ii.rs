// 3306. count-of-substrings-containing-every-vowel-and-k-consonants-ii
// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii

impl Solution {
    pub fn count_of_substrings(word: String, k: i32) -> i64 {
        let arr: Vec<char> = word.chars().collect();
        Self::count_at_least_k(&arr, k) - Self::count_at_least_k(&arr, k + 1)
    }

    fn count_at_least_k(arr: &[char], k: i32) -> i64 {
        let mut res = 0;
        let mut count = vec![0; 26];
        let mut mask = 0;
        let mut consonants = 0;
        let mut l = 0;
        let mut r = 0;

        let vowel_mask = Self::vowel_mask();

        while r < arr.len() {
            count[arr[r] as usize - 'a' as usize] += 1;
            if (vowel_mask & (1 << (arr[r] as usize - 'a' as usize))) != 0 {
                mask |= 1 << (arr[r] as usize - 'a' as usize);
            } else {
                consonants += 1;
            }

            while consonants >= k && mask == vowel_mask {
                res += (arr.len() - r) as i64;
                if (vowel_mask & (1 << (arr[l] as usize - 'a' as usize))) == 0 {
                    consonants -= 1;
                } else {
                    count[arr[l] as usize - 'a' as usize] -= 1;
                    if count[arr[l] as usize - 'a' as usize] == 0 {
                        mask ^= 1 << (arr[l] as usize - 'a' as usize);
                    }
                }
                l += 1;
            }
            r += 1;
        }
        res
    }

    fn vowel_mask() -> usize {
        let mut mask = 0;
        mask |= 1; // a
        mask |= 1 << ('e' as usize - 'a' as usize);
        mask |= 1 << ('i' as usize - 'a' as usize);
        mask |= 1 << ('o' as usize - 'a' as usize);
        mask |= 1 << ('u' as usize - 'a' as usize);
        mask
    }
}
