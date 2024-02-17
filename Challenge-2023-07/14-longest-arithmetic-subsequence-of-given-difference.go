package main

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func longestSubsequence(arr []int, difference int) int {
	n := len(arr)
	dp := make(map[int]int)
	res := 0
	for i := 0; i < n; i++ {
		x := arr[i]
		y := x - difference
		l := 1
		if _, ok := dp[y]; ok {
			l = max2(l, 1+dp[y])
		}
		if _, okx := dp[x]; okx {
			dp[x] = max2(dp[x], l)
		} else {
			dp[x] = l
		}
		res = max2(res, l)
	}
	return res
}
