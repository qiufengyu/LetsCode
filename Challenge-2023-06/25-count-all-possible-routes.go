package main

func abs(a int) int {
	if a <= 0 {
		return -a
	}
	return a
}

func countRoutes(locations []int, start int, finish int, fuel int) int {
	n := len(locations)
	dp := make([]([]int), n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, fuel+1)
		for j := 0; j <= fuel; j++ {
			dp[i][j] = 0
		}
	}
	for j := 0; j <= fuel; j++ {
		dp[finish][j] = 1
	}
	for i := 0; i <= fuel; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if k != j && (abs(locations[j]-locations[k]) <= i) {
					dp[j][i] = (dp[j][i] + dp[k][i-abs(locations[j]-locations[k])]) % 1000000007
				}
			}
		}
	}
	return dp[start][fuel]
}
