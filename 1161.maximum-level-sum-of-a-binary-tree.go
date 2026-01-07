/*
 * @lc app=leetcode id=1161 lang=golang
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

package main

import "math"

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"

type pair struct {
	first  int
	second *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	queue := []pair{}
	queue = append(queue, pair{1, root})
	var (
		prev_level int = 0
		level_sum  int = math.MinInt
		max_sum    int = math.MinInt
		ret        int = math.MinInt
	)

	for len(queue) > 0 {
		cur_level, cur_node := queue[0].first, queue[0].second
		queue = queue[1:]

		if cur_level != prev_level {
			if max_sum < level_sum {
				ret = prev_level
			}
			max_sum = max(max_sum, level_sum)
			level_sum = 0
			prev_level = cur_level
		}

		level_sum += cur_node.Val

		if cur_node.Left != nil {
			queue = append(queue, pair{cur_level + 1, cur_node.Left})
		}
		if cur_node.Right != nil {
			queue = append(queue, pair{cur_level + 1, cur_node.Right})
		}
	}

	if max_sum < level_sum {
		ret = prev_level
	}
	return ret
}

// @lc code=end
