package main

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func longestSubarray(nums []int) int {
	counts := make([]int, 0)
	count := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			counts = append(counts, count)
			count = 0
		} else {
			count++
		}
	}
	counts = append(counts, count)
	// because we must delete one element
	res := counts[0] - 1
	for i := 0; i < len(counts)-1; i++ {
		res = max2(res, counts[i]+counts[i+1])
	}
	return res
}
