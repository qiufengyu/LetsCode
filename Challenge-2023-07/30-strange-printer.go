package main

func min2(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func strangePrinter(s string) int {
	n := len(s)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		dp[i][i] = 1
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			dp[i][j] = dp[i][j-1] + 1
			for k := i; k < j; k++ {
				if s[k] == s[j] {
					tmp := dp[i][k] + dp[k+1][j-1]
					if k+1 > j-1 {
						tmp = dp[i][k]
					}
					dp[i][j] = min2(dp[i][j], tmp)
				}
			}
		}
	}
	return dp[0][n-1]
}
