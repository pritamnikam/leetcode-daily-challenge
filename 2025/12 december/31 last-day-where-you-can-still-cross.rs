// last-day-where-you-can-still-cross
// https://leetcode.com/problems/last-day-where-you-can-still-cross

impl Solution {
    pub fn latest_day_to_cross(row: i32, col: i32, cells: Vec<Vec<i32>>) -> i32 {
        let (r, c) = (row as usize, col as usize);
        let n = r * c;
        let top = n;
        let bottom = n + 1;

        let mut parent: Vec<usize> = (0..=n+1).collect();
        let mut rank = vec![0; n+2];
        let mut land = vec![false; n];

        fn find(p: &mut Vec<usize>, x: usize) -> usize {
            if p[x] != x {
                p[x] = find(p, p[x]);
            }
            p[x]
        }

        let dir = [(1,0),(-1,0),(0,1),(0,-1)];

        for d in (0..cells.len()).rev() {
            let rr = (cells[d][0]-1) as usize;
            let cc = (cells[d][1]-1) as usize;
            let id = rr * c + cc;
            land[id] = true;

            for (dr, dc) in dir {
                let nr = rr as i32 + dr;
                let nc = cc as i32 + dc;
                if nr>=0 && nc>=0 && (nr as usize)<r && (nc as usize)<c {
                    let nid = nr as usize * c + nc as usize;
                    if land[nid] {
                        let a = find(&mut parent, id);
                        let b = find(&mut parent, nid);
                        if a != b {
                            if rank[a] < rank[b] { parent[a] = b; }
                            else if rank[a] > rank[b] { parent[b] = a; }
                            else { parent[b] = a; rank[a]+=1; }
                        }
                    }
                }
            }

            if rr == 0 {
                let a = find(&mut parent, id);
                let b = find(&mut parent, top);
                if a != b { parent[b] = a; }
            }
            if rr == r-1 {
                let a = find(&mut parent, id);
                let b = find(&mut parent, bottom);
                if a != b { parent[b] = a; }
            }

            if find(&mut parent, top) == find(&mut parent, bottom) {
                return d as i32;
            }
        }
        0
    }
}
