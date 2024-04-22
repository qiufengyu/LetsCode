package main

import "fmt"

func findFarmland(land [][]int) [][]int {
    res := [][]int {}
	m, n := len(land), len(land[0])
	for i := 0; i < m; i += 1 {
		for j := 0; j < n; j += 1 {
			if land[i][j] == 1 {
				rect := []int {i, j, 0, 0}
				for i < m && land[i][rect[1]] == 1 {
					i += 1
				}
				for j < n && land[rect[0]][j] == 1 {
					j += 1
				}
                rect[2] = i - 1
				rect[3] = j - 1
				for x := rect[0]; x <= rect[2]; x += 1 {
					for y := rect[1]; y <= rect[3]; y += 1 {
						land[x][y] = 0
					}
				}							
				res = append(res, rect)
				i = rect[0]
				j = rect[1]
			}
		}
	}
	return res
}