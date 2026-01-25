/*
 * @lc app=leetcode id=1984 lang=golang
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

package main

import (
	"sort"
)

// @lc code=start
func minimumDifference(nums []int, k int) int {
	if len(nums) == 1 {
		return 0
	}

	sort.Ints(nums)

	var ret int = 1e5 + 1
	for i := 0; i+k <= len(nums); i++ {
		diff := nums[i] - nums[i+k-1]
		if diff < 0 {
			diff *= -1
		}
		ret = min(diff, ret)
	}
	return ret
}

// @lc code=end
