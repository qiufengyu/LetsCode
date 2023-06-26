package main

func max2(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxProfit(prices []int, fee int) int {
	dp0, dp1 := 0, -prices[0]
	for i := 0; i < len(prices); i++ {
		tmp := dp0
		dp0 = max2(dp0, dp1+prices[i]-fee) // sell
		dp1 = max2(dp1, tmp-prices[i])     // buy
	}
	return dp0
}
