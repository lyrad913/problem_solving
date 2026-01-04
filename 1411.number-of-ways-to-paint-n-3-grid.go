/*
 * @lc app=leetcode id=1411 lang=golang
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */
package main

// @lc code=start
func numOfWays(n int) int {
	ret1, ret2 := int64(6), int64(6)
	var mod int64 = 1e9 + 7

	for i := 0; i < n-1; i++ {
		ret1, ret2 = ((2*(ret1%mod)%mod)+(2*(ret2%mod)%mod))%mod, ((2*(ret1%mod)%mod)+(3*(ret2%mod)%mod))%mod
	}

	return int(((ret1 % mod) + (ret2 % mod)) % mod)
}

// @lc code=end
