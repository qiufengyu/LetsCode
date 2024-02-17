package main

func min2(a, b int) int {
	if a >= b {
		return b
	}
	return a
}

func minExtraChar(s string, dictionary []string) int {
	n := len(s)
	dictSet := map[string]bool{}
	for i := 0; i < len(dictionary); i++ {
		dictSet[dictionary[i]] = true
	}
	dp := make([]int, n+1)
	for i := n - 1; i >= 0; i-- {
		dp[i] = dp[i+1] + 1
		for j := i; j < n; j++ {
			cs := s[i : j+1]
			if _, ok := dictSet[cs]; ok {
				dp[i] = min2(dp[i], dp[j+1])
			}
		}
	}
	return dp[0]
}
