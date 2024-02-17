package main

import "sort"

func maxRunTime(n int, batteries []int) int64 {
	nb := len(batteries)
	sort.Ints(batteries)
	sum := int64(0)
	for i := 0; i < nb; i++ {
		sum += int64(batteries[i])
	}
	i := nb - 1
	for i >= 0 && (sum/int64(n)) < int64(batteries[i]) {
		sum -= int64(batteries[i])
		n--
		i--
	}
	return sum / int64(n)
}
