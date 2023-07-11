package main

import "sort"

type int64Slice []int64

func (arr int64Slice) Len() int {
	return len(arr)
}

func (arr int64Slice) Swap(i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func (arr int64Slice) Less(i, j int) bool {
	return arr[i] < arr[j]
}

func putMarbles(weights []int, k int) int64 {
	n := len(weights)
	var mx, mn int64 = int64(weights[0] + weights[n-1]), int64(weights[0] + weights[n-1])
	adjSum := make([]int64, n-1)
	for i := 0; i < n-1; i++ {
		adjSum[i] = int64(weights[i] + weights[i+1])
	}
	adjSumInt64 := int64Slice(adjSum)
	sort.Sort(adjSumInt64)
	for j := 0; j < k-1; j++ {
		mx += adjSumInt64[n-2-j]
		mn += adjSumInt64[j]
	}
	return mx - mn
}
