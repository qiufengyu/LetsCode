package main

import "fmt"

func change(amount int, coins []int) int {
	if amount == 0 {
		return 1
	}
	n := len(coins)
	dp := make([][]int, amount+1)
	for i := 0; i <= amount; i++ {
		dp[i] = make([]int, n+1)
	}
	for i := 1; i <= amount; i++ {
		for j := 1; j <= n; j++ {
			dp[i][j] += dp[i][j-1]
			if i >= coins[j-1] {
				dp[i][j] += dp[i-coins[j-1]][j]
				if i == coins[j-1] {
					dp[i][j]++
				}
			}
			// fmt.Println(i, j, dp[i][j])
		}
	}
	return dp[amount][n]
}

func main() {
	amount := 5
	coins := []int{1, 2, 5}
	fmt.Println(change(amount, coins))
}
