package main

import "sort"

func test(nums []int, p int, diff int, n int) bool {
	v := 0
	for i := 0; i < n-1; i++ {
		if nums[i+1]-nums[i] <= diff {
			v++
			i++
		}
		if v >= p {
			return true
		}
	}
	return false
}

func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	n := len(nums)
	l, r := 0, nums[n-1]-nums[0]
	for l < r {
		m := l + (r-l)/2
		if test(nums, p, m, n) {
			r = m
		} else {
			l = m + 1
		}
	}
	return l
}
