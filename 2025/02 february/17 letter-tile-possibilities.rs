// 1079. letter-tile-possibilities
// https://leetcode.com/problems/letter-tile-possibilities/

impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut agg: Vec<usize> = vec![0; 26];
        for &b in tiles.as_bytes() {
            agg[(b- 'A' as u8) as usize] +=1;
        }

        Self::helper(&mut agg)
    }

    fn helper(
        agg: &mut Vec<usize>
    ) -> i32 {
        let mut num: i32 = 0;

        for i in 0..26 {
            if agg[i] > 0 {
                agg[i] -= 1;
                num += 1;
                num += Self::helper(agg);
                agg[i] += 1;
            }
        }
        num
    }


}
