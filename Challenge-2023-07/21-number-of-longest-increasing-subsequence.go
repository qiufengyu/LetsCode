package main

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func findNumberOfLIS(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 1
	}
	dp, count := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = 1
		count[i] = 1
	}
	maxLen := 0
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				if dp[j]+1 > dp[i] {
					dp[i] = dp[j] + 1
					count[i] = count[j]
				} else if dp[j]+1 == dp[i] {
					count[i] += count[j]
				}
			}
		}
		maxLen = max2(maxLen, dp[i])
	}
	res := 0
	for i := 0; i < n; i++ {
		if dp[i] == maxLen {
			res += count[i]
		}
	}
	return res
}
