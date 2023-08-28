package main

func canCross(stones []int) bool {
	n := len(stones)
	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n+1)
	}
	dp[0][1] = true
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			jump := stones[i] - stones[j]
			if jump <= j+1 {
				dp[i][jump] = (dp[j][jump-1] || dp[j][jump] || dp[j][jump+1])
				if i == n-1 && dp[i][jump] {
					return true
				}
			}
		}
	}
	return false
}
