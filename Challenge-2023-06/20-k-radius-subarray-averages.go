package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func getAverages(nums []int, k int) []int {
	n := len(nums)
	res := make([]int, n)
	for i := range res {
		res[i] = -1
	}
	sum := 0
	start := min(n, 2*k)
	for i := 0; i < start; i++ {
		sum += nums[i]
	}
	for i := k; i+k < n; i++ {
		sum += nums[start+i-k]
		res[i] = sum / (2*k + 1)
		sum -= nums[i-k]
	}
	return res
}

func main() {
	nums := []int{7, 4, 3, 9, 1, 8, 5, 2, 6}
	k := 4
	res := getAverages(nums, k)
	fmt.Println(res)
}
