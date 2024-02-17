package main

func validPartition(nums []int) bool {
	n := len(nums)
	dp := make([]bool, n+1)
	dp[0] = true
	for i := 0; i < n; i++ {
		// case 1: check 2 same number
		if i > 0 && nums[i] == nums[i-1] {
			dp[i+1] = (dp[i+1] || dp[i-1])
		}
		// case 2: check 3 same number
		if i > 1 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2] {
			dp[i+1] = (dp[i+1] || dp[i-2])
		}
		// case 3: 3 continuous number
		if i > 1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2 {
			dp[i+2] = (dp[i+1] || dp[i-2])
		}
	}
	return dp[n]
}
