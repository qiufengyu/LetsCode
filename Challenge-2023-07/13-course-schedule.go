package main

import "fmt"

func checkCourse(course int, graph map[int][]int, visited map[int]int) bool {
	// this is import to avoid re-check if it has been evaluated from other courses14-
	if visited[course] == 2 {
		return true
	}
	visited[course] = 1
	preCourses := graph[course]
	for _, pc := range preCourses {
		if visited[pc] == 1 {
			return false
		}
		if !checkCourse(pc, graph, visited) {
			return false
		}
	}
	visited[course] = 2
	return true
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	graph := make(map[int][]int)
	for _, r := range prerequisites {
		cur, prev := r[0], r[1]
		if _, ok := graph[prev]; ok {
			graph[prev] = append(graph[prev], cur)
		} else {
			graph[prev] = make([]int, 1)
			graph[prev][0] = cur
		}
	}
	for c := 0; c < numCourses; c++ {
		if _, ok := graph[c]; ok {
			visited := make(map[int]int)
			for cc := 0; cc < numCourses; cc++ {
				visited[cc] = 0
			}
			chk := checkCourse(c, graph, visited)
			if !chk {
				return false
			}
		}
	}
	return true
}

func main() {
	var prerequisites = [][]int{{1, 4}, {2, 4}, {3, 1}, {3, 2}}
	numCourses := 5
	res := canFinish(numCourses, prerequisites)
	fmt.Printf("res: %v\n", res)
}
