package main

import (
	"fmt"
	"math"
)

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min2(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func maxArray(mem []int) int {
	res := mem[0]
	for i := 1; i < len(mem); i++ {
		res = max2(res, mem[i])
	}
	return res
}

func backtracking(mem []int, res *int, idx int, cookies []int, k int) {
	if idx == len(cookies) {
		*res = min2(*res, maxArray(mem))
	} else {
		if *res <= maxArray(mem) {
			return
		}
		for i := 0; i < k; i++ {
			mem[i] += cookies[idx]
			backtracking(mem, res, idx+1, cookies, k)
			mem[i] -= cookies[idx]
		}
	}
}

func distributeCookies(cookies []int, k int) int {
	mem := make([]int, k)
	res := math.MaxInt
	for i := 0; i < k; i++ {
		mem[i] = 0
	}
	backtracking(mem, &res, 0, cookies, k)
	return res
}
