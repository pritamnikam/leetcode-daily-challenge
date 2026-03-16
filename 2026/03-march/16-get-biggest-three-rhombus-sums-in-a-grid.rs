// get-biggest-three-rhombus-sums-in-a-grid
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid


struct Sorted3 {
    a:i32,b:i32,c:i32
}
impl Sorted3 {
    pub fn new() -> Self {
       Sorted3{a:0,b:0,c:0}
    }
    pub fn add(&mut self, x:i32) {
        if x > self.a {
            self.c = self.b;
            self.b = self.a;
            self.a = x;
        } 
        else if x == self.a {}
        else if x > self.b {
            self.c = self.b;
            self.b = x;
        }
        else if x == self.b {}
        else if x > self.c {
            self.c = x;
        }
    }

    pub fn res(&self) -> Vec<i32> {
        return vec![self.a,self.b,self.c];
    }
}

impl Solution {
    pub fn get_biggest_three(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let lenx = grid[0].len(); let leny = grid.len();
        if lenx ==1 || leny==1 {
            let mut res = grid.into_iter().flatten().map(|x| x).collect::<Vec<i32>>();
            res.sort(); res.dedup();
            return res.into_iter().rev().take(3).collect();
        }

        let maxx = lenx -1; let maxy = leny -1;
        let mut lsum:Vec<Vec<i32>> = Vec::with_capacity(leny);
        let mut rsum:Vec<Vec<i32>> = Vec::with_capacity(leny);

        let mut lastr = &vec![0;lenx]; let mut lastl = &vec![0;lenx];
        for row in grid.iter() {
            let mut rrow = vec![0;lenx]; let mut lrow = vec![0;lenx];
            rrow[0] = row[0]; 
            rrow[maxx] = lastr[maxx-1] + row[maxx];
            lrow[maxx] = row[maxx];            
            lrow[0] = lastl[1] + row[0];
            for i in 1..maxx {
                rrow[i] = lastr[i-1] + row[i];
                lrow[i] = lastl[i+1] + row[i];
            }
            rsum.push(rrow); lsum.push(lrow);
            lastr = rsum.last().unwrap(); lastl = lsum.last().unwrap();
        }
        
        let mut res = Sorted3::new();
        for j in 0..leny {
            for i in 0..lenx {
                res.add(grid[j][i]);
                let border_init;
                if j>0 && i>0 {border_init = -rsum[j-1][i-1] -lsum[j][i]}
                else {border_init = -lsum[j][i]};
                for k in 1..=i.min(maxx-i).min((maxy-j)/2) {
                    let mut border = border_init;

                    border += rsum[j+k][i+k];
                    border += rsum[j+(k<<1)][i];
                    border -= rsum[j+k][i-k];

                    border += lsum[j+k][i-k];
                    border += lsum[j+(k<<1)-1][i+1];
                    border -= lsum[j+k][i+k];

                    res.add(border);
                }
            }
        }
        return res.res();
    }
}
