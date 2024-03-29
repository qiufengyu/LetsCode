package main

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	left, right := 0, m*n-1
	mid := left + (right-left)/2
	for left <= right {
		mid = left + (right-left)/2
		mm := matrix[mid/n][mid%n]
		if mm == target {
			return true
		} else if mm < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return false
}
