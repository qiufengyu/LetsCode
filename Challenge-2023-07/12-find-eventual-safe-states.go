package main

import (
	"fmt"
	"sort"
)

func eventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	inGraph := make([][]int, n)
	visited := make(map[int]bool)
	res := make(map[int]bool)
	resInit := 0
	for i := 0; i < n; i++ {
		inGraph[i] = make([]int, 0)
	}
	for i := 0; i < n; i++ {
		nbrs := graph[i]
		if len(nbrs) == 0 {
			res[i] = true
		}
		for _, nbr := range nbrs {
			inGraph[nbr] = append(inGraph[nbr], i)
		}
	}
	// to find all candidates
	for resInit != len(res) {
		resInit = len(res)
		for r, _ := range res {
			if _, ok := visited[r]; !ok {
				visited[r] = true
				for _, x := range inGraph[r] {
					terminate := true
					for _, y := range graph[x] {
						if _, okRes := res[y]; !okRes {
							terminate = false
						}
					}
					if terminate {
						res[x] = true
					}
				}
			}
		}
	}
	// return result and sort keys in res
	resArray := make([]int, 0)
	for k, _ := range res {
		resArray = append(resArray, k)
	}
	sort.Ints(resArray)
	return resArray
}

func main() {
	var graph = [][]int{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}}
	res := eventualSafeNodes(graph)
	fmt.Printf("res: %v\n", res)
}
