/*
 * @lc app=leetcode id=1975 lang=golang
 *
 * [1975] Maximum Matrix Sum
 */

package main

// @lc code=start
func maxMatrixSum(matrix [][]int) int64 {
	var sum int64 = 0
	n_minus := 0
	min_abs := 100001

	for _, row := range matrix {
		for _, elem := range row {
			abs_elem := max(elem, -elem)
			sum += int64(abs_elem)
			min_abs = min(min_abs, abs_elem)
			if elem < 0 {
				n_minus += 1
			}
		}
	}

	if n_minus%2 == 0 {
		return sum
	} else {
		return sum - 2*int64(min_abs)
	}
}

// @lc code=end
