package main

func isInterleave(s1 string, s2 string, s3 string) bool {
	l1, l2, l3 := len(s1), len(s2), len(s3)
	if l1+l2 != l3 {
		return false
	}
	dp := make([][]bool, l1+1)
	for i := 0; i <= l1; i++ {
		dp[i] = make([]bool, l2+1)
	}
	// base case, i.e. example 3
	dp[0][0] = true
	for i := 0; i <= l1; i++ {
		for j := 0; j <= l2; j++ {
			k := i + j - 1
			if i > 0 {
				dp[i][j] = dp[i][j] || (dp[i-1][j] && s3[k] == s1[i-1])
			}
			if j > 0 {
				dp[i][j] = dp[i][j] || (dp[i][j-1] && s3[k] == s2[j-1])
			}
		}
	}
	return dp[l1][l2]
}
