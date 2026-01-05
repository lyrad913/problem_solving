/*
 * @lc app=leetcode id=1975 lang=rust
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut sum: i64 = 0;
        let mut n_minus = 0;
        let mut min_abs = 100001;

        for row in matrix.iter() {
            for &elem in row.iter() {
                sum += elem.abs() as i64;
                min_abs = std::cmp::min(min_abs, elem.abs());

                if (elem < 0) {
                    n_minus += 1;
                }
            }
        }

        if (n_minus % 2 == 0) {
            sum
        } else {
            sum - 2 * (min_abs as i64)
        }
    }
}
// @lc code=end
