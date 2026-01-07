/*
 * @lc app=leetcode id=1339 lang=golang
 *
 * [1339] Maximum Product of Splitted Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

package main

import (
	"math"
)

const mod int64 = 1e9 + 7

var (
	total_sum    int = 0
	partial_sums []int
)

func dfs(root *TreeNode) int {
	if root == nil {
		return 0
	}

	partial_sum := root.Val + dfs(root.Left) + dfs(root.Right)
	partial_sums = append(partial_sums, partial_sum)

	return partial_sum
}

func maxProduct(root *TreeNode) int {
	partial_sums = []int{}
	total_sum = dfs(root)

	min_diff := math.MaxInt
	var partial_sum int

	for _, s := range partial_sums {
		cand := (total_sum - 2*s)
		if cand < 0 {
			cand *= -1
		}

		if min_diff > cand {
			min_diff = cand
			partial_sum = s
		}
	}

	return int(((int64(total_sum-partial_sum) % mod) * int64(partial_sum) % mod) % mod)
}

// @lc code=end
