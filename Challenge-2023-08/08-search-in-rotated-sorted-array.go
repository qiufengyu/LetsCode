package main

import "fmt"

func search(nums []int, target int) int {
	l, r := 0, len(nums)-1
	m := l + (r-l)/2
	for l <= r {
		m = l + (r-l)/2
		fmt.Println(l, r, m)
		cand := nums[m]
		if cand == target {
			return m
		}
		if nums[l] <= nums[m] {
			if cand < target {
				l = m + 1
			} else {
				if target < nums[l] {
					l = m + 1
				} else {
					r = m - 1
				}
			}
		} else {
			if cand > target {
				r = m - 1
			} else {
				if nums[r] < target {
					r = m - 1
				} else {
					l = m + 1
				}
			}
		}
	}
	return -1
}

func main() {
	var nums = []int{3, 1}
	var target int = 2
	fmt.Println(search(nums, target))
}
