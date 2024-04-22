package main

import "fmt"

func numIslands(grid [][]byte) int {
    res := 0
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i += 1 {
		for j := 0; j < n; j += 1 {
			if grid[i][j] == '1' {
				dfs(grid, m, n, i, j)
				res += 1
			}
		}
	}
	return res	
}

func dfs(grid [][]byte, m, n, i, j int) {
	grid[i][j] = '0'
	if i + 1 < m && grid[i+1][j] == '1' { 
		dfs(grid, m, n, i+1, j)
	}
	if i - 1 >= 0 && grid[i-1][j] == '1' {
		dfs(grid, m, n, i-1, j)
	}
	if j + 1 < n && grid[i][j+1] == '1' {
		dfs(grid, m, n, i, j+1)
	}
	if j - 1 >= 0 && grid[i][j-1] == '1' {
		dfs(grid, m, n, i, j-1)
	}
}