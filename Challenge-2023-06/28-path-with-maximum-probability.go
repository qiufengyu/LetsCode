package main

import "fmt"

func maxProbability(n int, edges [][]int, succProb []float64, start int, end int) float64 {
	probs := make([]float64, n)
	visited := make([]bool, n)
	for i := 0; i < n; i++ {
		probs[i] = -1.0
		visited[i] = false
	}
	probs[start] = 1.0
	graph := make(map[int](map[int]float64))
	for i := 0; i < n; i++ {
		graph[i] = make(map[int]float64)
	}
	for i := 0; i < len(edges); i++ {
		edge := edges[i]
		prob := succProb[i]
		graph[edge[0]][edge[1]] = prob
		graph[edge[1]][edge[0]] = prob
	}
	// use queue
	q := make([]int, 0)
	q = append(q, start)
	for len(q) > 0 {
		node := q[0]
		q = q[1:]
		for k, v := range graph[node] {
			newProb := probs[node] * v
			if newProb > probs[k] {
				probs[k] = newProb
				q = append(q, k)
			}
		}
	}
	if probs[end] < 0 {
		return 0.0
	}
	return probs[end]
}

// apply dijkstra algo from start node -> TLE
// for i := 0; i < n; i++ {
// 	maxProb := -1.0
// 	maxNode := -1
// 	for j := 0; j < n; j++ {
// 		if !visited[j] && probs[j] > 0 && probs[j] >= maxProb {
// 			maxProb = probs[j]
// 			maxNode = j
// 		}
// 	}
// 	if maxNode == end {
// 		return maxProb
// 	}
// 	if maxNode < 0 {
// 		return 0.0
// 	}
// 	// update prob of all reachable nodes
// 	visited[maxNode] = true
// 	probs[maxNode] = maxProb
// 	for j := 0; j < n; j++ {
// 		if !visited[j] {
// 			if p, ok := graph[maxNode][j]; ok {
// 				if probs[j] < maxProb*p {
// 					probs[j] = maxProb * p
// 				}
// 			}
// 		}
// 	}
// }
