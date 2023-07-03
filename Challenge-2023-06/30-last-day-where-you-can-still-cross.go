package main

import "fmt"

type Item struct {
	ri int
	ci int
}

func check(row int, col int, cells [][]int, mid int) bool {
	dirs := [][]int{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
	grid := make([][]int, row)
	for i := 0; i < row; i++ {
		grid[i] = make([]int, col)
	}
	for i := 0; i < mid; i++ {
		grid[cells[i][0]-1][cells[i][1]-1] = 1
	}
	q := make([]*Item, 0)
	for i := 0; i < col; i++ {
		if grid[0][i] == 0 {
			q = append(q, &Item{ri: 0, ci: i})
			grid[0][i] = -1
		}
	}
	for len(q) > 0 {
		tp := q[0]
		q = q[1:]
		ri, ci := tp.ri, tp.ci
		if ri == row-1 {
			return true
		}
		for j := 0; j < 4; j++ {
			nri, nci := ri+dirs[j][0], ci+dirs[j][1]
			if nri >= 0 && nri < row && nci >= 0 && nci < col && grid[nri][nci] == 0 {
				grid[nri][nci] = -1
				q = append(q, &Item{ri: nri, ci: nci})
			}
		}
	}
	return false
}

func latestDayToCross(row int, col int, cells [][]int) int {
	left, right := 1, len(cells)
	res := 0
	for left <= right {
		mid := left + (right-left)/2
		if check(row, col, cells, mid) {
			res = mid
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return res
}
