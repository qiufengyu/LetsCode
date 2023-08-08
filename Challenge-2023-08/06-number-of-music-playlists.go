package main

const MOD int64 = 1000000007

func min2(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func numMusicPlaylists(n int, goal int, k int) int {
	dp := make([][]int, goal+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for i := 0; i <= goal; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = 0
		}
	}
	dp[0][0] = 1
	for i := 1; i <= goal; i++ {
		for j := 1; j <= min2(i, n); j++ {
			dp[i][j] = int(int64(dp[i-1][j-1]) * int64(n-j+1) % MOD)
			if j > k {
				dp[i][j] = int((int64(dp[i][j]) + int64(dp[i-1][j])*int64(j-k)) % MOD)
			}
		}
	}
	return dp[goal][n]
}
