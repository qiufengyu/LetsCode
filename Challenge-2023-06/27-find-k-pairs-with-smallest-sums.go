package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	i1       int // The value of the item; arbitrary.
	i2       int
	priority int // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil // avoid memory leak
	*pq = old[0 : n-1]
	return item
}

// update modifies the priority and value of an Item in the queue.
func (pq *PriorityQueue) update(item *Item, i1 int, i2 int, priority int) {
	item.i1 = i1
	item.i2 = i2
	item.priority = priority
}

func min2(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	pq := make(PriorityQueue, 0)
	heap.Init(&pq)
	count := 0
	for i := 0; i < len(nums1); i++ {
		for j := 0; j < len(nums2); j++ {
			sum := nums1[i] + nums2[j]
			if len(pq) < k {
				item := &Item{
					i1:       i,
					i2:       j,
					priority: sum,
				}
				count++
				heap.Push(&pq, item)
			} else if pq[0].priority > sum {
				item := &Item{
					i1:       i,
					i2:       j,
					priority: sum,
				}
				count++
				heap.Push(&pq, item)
				heap.Pop(&pq)
			} else {
				break // the j after is not needed because sum will always increase
			}
		}
	}
	resSize := min2(k, len(nums1)*len(nums2))
	res := make([]([]int), resSize)
	for resSize > 0 && len(pq) > 0 {
		tp := heap.Pop(&pq).(*Item)
		res[resSize-1] = []int{nums1[tp.i1], nums2[tp.i2]}
		resSize--
	}
	return res
}

func main() {
	nums1 := []int{1, 7, 11}
	nums2 := []int{2, 4, 6}
	k := 3
	res := kSmallestPairs(nums1, nums2, k)
	fmt.Println(res)
}
