package main

func min2(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func minSubArrayLen(target int, nums []int) int {
	left, right := 0, 0
	sum := 0
	res := 100001
	for right < len(nums) {
		sum += nums[right]
		for sum >= target {
			sum -= nums[left]
			res = min2(res, right-left+1)
			left++
		}
		right++
	}
	if res == 100001 {
		return 0
	}
	return res
}
