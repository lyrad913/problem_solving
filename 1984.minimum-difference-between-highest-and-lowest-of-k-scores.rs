/*
 * @lc app=leetcode id=1984 lang=rust
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

// @lc code=start
impl Solution {
    pub fn minimum_difference(mut nums: Vec<i32>, k: i32) -> i32 {
        if (k == 1) {
            return 0;
        }

        nums.sort();

        let mut ret = 100001;
        let k = k as usize;
        let mut i = 0;
        while i + k <= nums.len() {
            ret = std::cmp::min(ret, nums[i + k - 1] - nums[i]);
            i += 1;
        }

        ret
    }
}
// @lc code=end
