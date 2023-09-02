package main

func minTaps(n int, ranges []int) int {
	left, right := 0, 0
	res := 0
	for right < n {
		for i := 0; i <= n; i++ {
			if i-ranges[i] <= left && i+ranges[i] >= right {
				right = i + ranges[i]
			}
		}
		if right == left {
			return -1
		}
		res++
		left = right
	}
	return res
}
