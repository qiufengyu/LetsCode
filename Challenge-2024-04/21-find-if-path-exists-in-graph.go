package main

func validPath(n int, edges [][]int, source int, destination int) bool {
	parent := make([]int, n)
	for i := 0; i < n; i += 1 {
		parent[i] = i
	}
	for _, edge := range edges {
		union(parent, edge[0], edge[1])
	}
	return find(parent, source) == find(parent, destination)
}

func union(parent []int, a, b int) {
	pa := find(parent, a)
	pb := find(parent, b)
	if pa != pb {
		if pa < pb {
			parent[pb] = pa
		} else {
			parent[pa] = pb
		}
	}
}

func find(parent []int, a int) int {
	for parent[a] != a {
		tmp := a
		a = find(parent, parent[a])
		parent[tmp] = a
	}
	return parent[a]
}
