package main

import (
	"fmt"
	"math"
)

func minFallingPathSum(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dp := make([]int, n)
	for j := 0; j < n; j += 1 {
		dp[j] = grid[0][j]
	}
	for i := 1; i < m; i += 1 {
		// find index of minimum two elements
		mi1 := -1
		mn1, mn2 := math.MaxInt, math.MaxInt
		for j := 0; j < n; j += 1 {
			if dp[j] <= mn1 {
				mn2 = mn1
				mn1 = dp[j]
				mi1 = j
			} else if dp[j] < mn2 {
				mn2 = dp[j]
			}
		}
		for j := 0; j < n; j += 1 {
			if j == mi1 {
				dp[j] = mn2 + grid[i][j]
			} else {
				dp[j] = mn1 + grid[i][j]
			}
		}
	}
	res := math.MaxInt
	for j := 0; j < n; j += 1 {
		res = min(res, dp[j])
	}
	return res
}

func main() {
	grid := make([][]int, 3)
	for i := 0; i < 3; i += 1 {
		grid[i] = make([]int, 3)
		grid[i][0] = i*3 + 1
		grid[i][1] = i*3 + 2
		grid[i][2] = i*3 + 3
	}
	fmt.Println(minFallingPathSum(grid))
}
