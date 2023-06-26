package main

import "fmt"

func minCost(nums []int, cost []int) int64 {
	var left, right = nums[0], nums[0]
	for _, v := range nums {
		if v < left {
			left = v
		}
		if v > right {
			right = v
		}
	}
	fmt.Println(left, right)
	var res int64 = 0
	for left < right {
		var m = (left + right) / 2
		cost1 := helper(nums, cost, m)
		cost2 := helper(nums, cost, m+1)
		if cost1 > cost2 {
			left = m + 1
			res = cost2
		} else {
			right = m
			res = cost1
		}
	}
	return res
}

func helper(nums []int, cost []int, candidate int) int64 {
	var totalCost int64 = 0
	for i := 0; i < len(nums); i++ {
		if nums[i] > candidate {
			totalCost += (int64(cost[i]) * int64(nums[i]-candidate))
		} else {
			totalCost += (int64(cost[i]) * int64(candidate-nums[i]))
		}
	}
	return totalCost
}

func main() {
	nums := []int{1, 3, 5, 2}
	cost := []int{2, 3, 1, 14}
	res := minCost(nums, cost)
	fmt.Println(res)
}
