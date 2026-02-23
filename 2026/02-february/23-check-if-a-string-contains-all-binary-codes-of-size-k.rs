// check-if-a-string-contains-all-binary-codes-of-size-k
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let lens = s.len();
        let mut need_chars = (k - 1 + (1 << k)) as usize;
        if need_chars > lens {return false}

        let mut bitmap = vec![0u8;1 << k];
        let k = k as usize;
        let mut bin_code = 0 as usize;
        let bin_mask:usize = (1 << k) -1;

        for c in s.bytes().take(k) {
            bin_code = (bin_code << 1) + (c - b'0') as usize;
        }
        bitmap[bin_code] = 1;
        need_chars -= k-1;

        for (idx, c) in s.bytes().enumerate().skip(k) {
            bin_code = ((bin_code << 1) & bin_mask) + (c - b'0') as usize;
            
            need_chars -= 1 - bitmap[bin_code] as usize; 
            bitmap[bin_code] = 1;

            if need_chars == 0 {return true}
            if lens - idx < need_chars {return false}
        }
        return true
    }
}
