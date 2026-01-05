// maximum-matrix-sum
// https://leetcode.com/problems/maximum-matrix-sum


// Intution: If the number of negative number is even, you can make all number to positive.
// Otherwise, You have to sacrifice a cell such that having a minimum absoulte value.
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        // store the sum of absolute values, track the smallest absolute value, and count the number of negative elements
        let n = matrix.len();
        let mut ans = 0i64; 
        let mut maximum_neg = i32::MAX;
        let mut cnt = 0;

        for i in 0..n {
            for j in 0..n {
                if matrix[i][j] < 0 {
                    cnt += 1;
                }
                let num = matrix[i][j].abs();
                maximum_neg = maximum_neg.min(num);
                ans += num as i64;
            }
        }

        if cnt % 2 == 1 {
            ans -= 2 * maximum_neg as i64
        }
        ans
    }
}
