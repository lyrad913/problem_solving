/*
 * @lc app=leetcode id=1390 lang=golang
 *
 * [1390] Four Divisors
 */
package main

// @lc code=start
func sumFourDivisors(nums []int) int {
	var n_divisors []int = make([]int, 1e5+1)
	var sum_divisors []int = make([]int, 1e5+1)

	for i := 1; i <= 1e5; i++ {
		for j := int64(i); j <= 1e5; j += int64(i) {
			n_divisors[j]++
			sum_divisors[j] += i
		}
	}

	var ret int = 0
	for _, num := range nums {
		if n_divisors[num] == 4 {
			ret += sum_divisors[num]
		}
	}

	return ret
}

// @lc code=end
