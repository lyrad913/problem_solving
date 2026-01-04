/*
 * @lc app=leetcode id=1390 lang=rust
 *
 * [1390] Four Divisors
 */

// @lc code=start
impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut n_divisors = vec![1; 100001];
        let mut sum_divisors = vec![1; 100001];

        for i in 2..100001 {
            for j in (i..100001).step_by(i as usize) {
                n_divisors[j] += 1;
                sum_divisors[j] += i as i32;
            }
        }

        let mut ret: i32 = 0;
        for num in nums {
            if (n_divisors[num as usize] == 4) {
                ret += sum_divisors[num as usize];
            }
        }

        ret
    }
}
// @lc code=end
