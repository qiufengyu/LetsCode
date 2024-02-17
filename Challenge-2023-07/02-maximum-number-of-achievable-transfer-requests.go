package main

import "fmt"

func getOnes(num int) int {
	count := 0
	for num != 0 {
		num = (num - 1) & num
		count++
	}
	return count
}

func maximumRequests(n int, requests [][]int) int {
	m := len(requests)
	res := 0
	for i := 0; i < (1 << m); i++ {
		candidates := getOnes(i)
		if candidates < res {
			continue
		}
		indegree := make([]int, n)
		idx := m
		for j := i; j > 0; j = (j >> 1) {
			m--
			if (j & 1) != 0 {
				indegree[requests[idx][0]]--
				indegree[requests[idx][1]]++
			}
		}
		// checking
		check := true
		for j := 0; j < n; j++ {
			if indegree[j] != 0 {
				check = false
				break
			}
		}
		if check {
			res = candidates
		}
	}
	return res
}
