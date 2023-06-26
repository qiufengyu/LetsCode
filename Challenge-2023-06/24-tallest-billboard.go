package main

import "fmt"

func max2(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min2(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a <= 0 {
		return -a
	}
	return a
}

func tallestBillboard(rods []int) int {
	n := len(rods)
	dp := make([](map[int]int), n)
	dp[0] = make(map[int]int)
	dp[0][0] = 0
	dp[0][rods[0]] = rods[0]
	for i := 1; i < n; i++ {
		fmt.Println(i)
		rod := rods[i]
		dp[i] = make(map[int]int)
		// add to neither
		for k, v := range dp[i-1] {
			dp[i][k] = v
		}
		for k, v := range dp[i-1] {
			diff := k
			taller := v
			shorter := v - k
			newTaller := 0
			// add to taller
			if _, ok := dp[i][diff+rod]; ok {
				newTaller = dp[i][diff+rod]
			}
			dp[i][diff+rod] = max2(newTaller, taller+rod)
			// add to shorter
			newDiff := abs(shorter + rod - taller)
			newTaller2 := max2(shorter+rod, taller)
			newTaller3 := 0
			if _, ok := dp[i][newDiff]; ok {
				newTaller3 = dp[i][newDiff]
			}
			dp[i][newDiff] = max2(newTaller2, newTaller3)
		}
	}
	return dp[n-1][0]
}

func main() {
	rods := []int{1, 2, 3, 6}
	res := tallestBillboard(rods)
	fmt.Println(res)
}
