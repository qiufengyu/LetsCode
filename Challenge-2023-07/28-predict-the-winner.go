package main

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func PredictTheWinner(nums []int) bool {
	n := len(nums)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		dp[i][i] = nums[i]
	}
	for l := 1; l < n; l++ {
		for i := 0; i < n-l; i++ {
			j := i + l
			dp[i][j] = max2(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])
		}
	}
	return dp[0][n-1] >= 0
}
