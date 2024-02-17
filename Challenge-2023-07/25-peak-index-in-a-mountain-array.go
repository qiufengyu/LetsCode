package main

func peakIndexInMountainArray(arr []int) int {
	low, high := 0, len(arr)
	m := (low + high) / 2
	for low < high {
		m = (low + high) / 2
		if arr[m] > arr[m-1] && arr[m] > arr[m+1] {
			return m
		} else if arr[m] < arr[m+1] && arr[m-1] < arr[m] {
			low = m
		} else {
			high = m
		}
	}
	return (low + high) / 2
}
