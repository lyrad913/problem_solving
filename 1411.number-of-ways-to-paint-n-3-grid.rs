/*
 * @lc app=leetcode id=1411 lang=rust
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
impl Solution {
    pub fn num_of_ways(n: i32) -> i32 {
        let mut ret1: i64 = 6;
        let mut ret2: i64 = 6;
        let m: i64 = 1_000_000_007;

        for _ in 0..n - 1 {
            let tmp1 = ((2 * (ret1 % m) % m) + (2 * (ret2 % m) % m)) % m;
            let tmp2 = ((2 * (ret1 % m) % m) + (3 * (ret2 % m) % m)) % m;

            ret1 = tmp1;
            ret2 = tmp2;
        }

        (((ret1 % m) + (ret2 % m)) % m) as i32
    }
}
// @lc code=end
