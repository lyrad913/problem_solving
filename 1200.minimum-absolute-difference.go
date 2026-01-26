/*
 * @lc app=leetcode id=1200 lang=golang
 *
 * [1200] Minimum Absolute Difference
 */

package main

import (
	"math"
	"sort"
)

// @lc code=start
func minimumAbsDifference(arr []int) [][]int {
	sort.Ints(arr)

	diff := math.MaxInt
	for i := 0; i < len(arr)-1; i++ {
		diff = min(arr[i+1]-arr[i], diff)
	}

	var ret [][]int
	for i := 0; i < len(arr)-1; i++ {
		if diff == arr[i+1]-arr[i] {
			ret = append(ret, []int{arr[i], arr[i+1]})
		}
	}
	return ret
}

// @lc code=end
