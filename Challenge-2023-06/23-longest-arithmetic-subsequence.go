package main

func max2(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func longestArithSeqLength(nums []int) int {
	res := 0
	n := len(nums)
	dp := make([](map[int]int), n)
	for i := 0; i < n; i++ {
		dp[i] = make(map[int]int)
		for j := 0; j < i; j++ {
			diff := nums[j] - nums[i]
			if _, ok := dp[j][diff]; ok {
				dp[i][diff] = 1 + dp[j][diff]
			} else {
				dp[i][diff] = 2
			}
			res = max2(res, dp[i][diff])
		}
	}
	return res
}
