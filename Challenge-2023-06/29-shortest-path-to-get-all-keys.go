package main

import "fmt"

type Item struct {
	ii   int
	jj   int
	mask int
}

func numOfBits(num int) int {
	bits := 0
	for num != 0 {
		bits++
		num = (num - 1) & num
	}
	return bits
}

func shortestPathAllKeys(grid []string) int {
	m := len(grid)
	n := len(grid[0])
	dirs := [4][2]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
	keys := 0
	q := make([]*Item, 0)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] >= 'a' && grid[i][j] <= 'z' {
				keys++
			} else if grid[i][j] == '@' {
				q = append(q, &Item{ii: i, jj: j, mask: 0})
			}
		}
	}
	visited := make(map[Item]bool)
	steps := 0
	for len(q) > 0 {
		sz := len(q)
		for i := 0; i < sz; i++ {
			current := q[0]
			q = q[1:]
			x, y, msk := current.ii, current.jj, current.mask
			fmt.Println(x, y, msk)
			if numOfBits(msk) == keys {
				return steps
			}
			for d := 0; d < 4; d++ {
				nx, ny := x+dirs[d][0], y+dirs[d][1]
				if nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] != '#' {
					newChar := grid[nx][ny]
					newMask := msk
					if newChar >= 'a' && newChar <= 'z' {
						newMask = newMask | (1 << (newChar - 'a'))
					}
					newItem := &Item{ii: nx, jj: ny, mask: newMask}
					if _, ok := visited[*newItem]; ok {
						continue
					}
					if (newChar >= 'A' && newChar <= 'Z') && (msk&(1<<(newChar-'A')) == 0) {
						continue
					}
					q = append(q, newItem)
					visited[*newItem] = true
				}
			}
		}
		steps++
	}
	return -1
}

func main() {
	grid := []string{"@abcdeABCDEFf"}
	res := shortestPathAllKeys(grid)
	fmt.Println(res)
}
