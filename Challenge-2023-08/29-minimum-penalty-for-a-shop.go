package main

import "fmt"

func bestClosingTime(customers string) int {
	n := len(customers)
	ns := make([]int, n+1)
	ys := make([]int, n+1)
	ncount, ycount := 0, 0
	ns[0] = 0
	ys[n] = 0
	for i := 0; i < n; i++ {
		if customers[i] == 'N' {
			ncount++
		}
		ns[i+1] = ncount
		if customers[n-1-i] == 'Y' {
			ycount++
		}
		ys[n-i-1] = ycount
	}
	res := -1
	penalty := n + 1
	for i := 0; i <= n; i++ {
		if penalty > ys[i]+ns[i] {
			penalty = ys[i] + ns[i]
			res = i
		}
	}
	return res
}

func main() {
	customers := "YYNY"
	fmt.Println(bestClosingTime(customers))
}
