package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	graph := make(map[int][]int)
	res := make([]int, 0)
	if root == nil {
		return res
	}
	q1 := make([](*TreeNode), 0)
	q1 = append(q1, root)
	graph[root.Val] = make([]int, 0)
	for len(q1) > 0 {
		sz := len(q1)
		for sz > 0 {
			node := q1[0]
			q1 = q1[1:]
			val := node.Val
			// bfs ensures the neighbor list are created from the level of parent node (top to bottom)
			if node.Left != nil {
				graph[val] = append(graph[val], node.Left.Val)
				graph[node.Left.Val] = make([]int, 0)
				graph[node.Left.Val] = append(graph[node.Left.Val], val)
				q1 = append(q1, node.Left)
			}
			if node.Right != nil {
				graph[val] = append(graph[val], node.Right.Val)
				graph[node.Right.Val] = make([]int, 0)
				graph[node.Right.Val] = append(graph[node.Right.Val], val)
				q1 = append(q1, node.Right)
			}
			sz--
		}
	}
	fmt.Printf("graph: %v\n", graph)
	q2 := make([]int, 0)
	visited := make(map[int]bool)
	q2 = append(q2, target.Val)
	visited[target.Val] = true
	for len(q2) > 0 {
		if k == 0 {
			return q2
		}
		sz := len(q2)
		for sz > 0 {
			t := q2[0]
			q2 = q2[1:]
			neighbors := graph[t]
			for _, n := range neighbors {
				if _, ok := visited[n]; !ok {
					q2 = append(q2, n)
					visited[n] = true
				}
			}
			sz--
		}
		k--
	}
	return res
}
