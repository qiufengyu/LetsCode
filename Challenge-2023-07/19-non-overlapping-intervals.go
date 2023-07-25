package main

import "sort"

type interval [][]int

func (itv interval) Len() int {
	return len(itv)
}

func (itv interval) Swap(a, b int) {
	itv[a], itv[b] = itv[b], itv[a]
}

func (itv interval) Less(a, b int) bool {
	return itv[a][1] < itv[b][1]
}

func eraseOverlapIntervals(intervals [][]int) int {
	if len(intervals) == 0 {
		return 0
	}
	sort.Sort(interval(intervals))
	nonOverlap := 0
	end := intervals[0][0] - 1
	for i := 0; i < len(intervals); i++ {
		if intervals[i][0] >= end {
			nonOverlap++
			end = intervals[i][1]
		}
	}
	return len(intervals) - nonOverlap
}
