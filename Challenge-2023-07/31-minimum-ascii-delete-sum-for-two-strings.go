package main

import "fmt"

type Item struct {
	length int
	iPrev  int
	jPrev  int
}

func min2(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func minimumDeleteSum(s1 string, s2 string) int {
	m, n := len(s1), len(s2)
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	for i := 0; i <= m; i++ {
		for j := 0; j <= n; j++ {
			if i == 0 && j == 0 {
				dp[i][j] = 0
			} else if i == 0 {
				dp[0][j] = dp[0][j-1] + int(s2[j-1])
			} else if j == 0 {
				dp[i][0] = dp[i-1][0] + int(s1[i-1])
			} else if s1[i-1] == s2[j-1] {
				dp[i][j] = dp[i-1][j-1]
				// fmt.Println("case 3", i, j, dp[i][j])
			} else {
				tmp1 := dp[i-1][j] + int(s1[i-1])
				tmp2 := dp[i][j-1] + int(s2[j-1])
				dp[i][j] = min2(tmp1, tmp2)
				// fmt.Println("case 4", i, j, dp[i][j])
			}
		}
	}
	return dp[m][n]
}

func main() {
	res := minimumDeleteSum("sea", "eat")
	fmt.Println(res)
}
