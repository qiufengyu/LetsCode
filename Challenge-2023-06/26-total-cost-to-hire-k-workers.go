// This is not correct, and I don't why why the priority queue does not work as expected

package main

import (
	"container/heap"
	"fmt"
)

type Item struct {
	value    int // The value of the item; arbitrary.
	priority int // The priority of the item in the queue.
	// The index is needed by update and is maintained by the heap.Interface methods.
	index int // The index of the item in the heap.
}

// A PriorityQueue implements heap.Interface and holds Items.
type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x any) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}

// update modifies the priority and value of an Item in the queue.
func (pq *PriorityQueue) update(item *Item, value int, priority int) {
	item.value = value
	item.priority = priority
	heap.Fix(pq, item.index)
}

func totalCost(costs []int, k int, candidates int) int64 {
	var res int64 = 0
	n := len(costs)
	left := candidates - 1
	right := n - candidates
	count := 0
	pq1 := make(PriorityQueue, candidates)
	pq2 := make(PriorityQueue, candidates)
	usedMap := make(map[int]bool)
	for i := 0; i < n; i++ {
		usedMap[i] = false
	}
	for i := 0; i < candidates; i++ {
		pq1[i] = &Item{
			value:    i,
			priority: costs[i],
			index:    i,
		}
		pq2[i] = &Item{
			value:    n - i - 1,
			priority: costs[n-i-1],
			index:    i,
		}
	}
	heap.Init(&pq1)
	heap.Init(&pq2)
	for left < n && right >= 0 && count < k {
		fmt.Println("pq1")
		for x := 0; x < pq1.Len(); x++ {
			fmt.Print(pq1[x].priority, ",")
		}
		fmt.Println()
		fmt.Println("pq2")
		for x := 0; x < pq2.Len(); x++ {
			fmt.Print(pq2[x].priority, ",")
		}
		fmt.Println()
		fmt.Println("count =", count, "|", left, ",", right)
		lMin := pq1[0]
		rMin := pq2[0]
		if lMin.priority < rMin.priority {
			res += int64(lMin.priority)
			usedMap[lMin.value] = true
			fmt.Println("selecting", lMin.priority, "from pq1")
			heap.Pop(&pq1)
			left++
			for left < n {
				if !usedMap[left] {
					pq1.Push(&Item{
						value:    left,
						priority: costs[left],
						index:    lMin.index,
					})
					break
				}
				left++
			}
		} else if lMin.priority > rMin.priority {
			res += int64(rMin.priority)
			usedMap[rMin.value] = true
			heap.Pop(&pq2)
			fmt.Println("selecting", rMin.priority, "from pq2")
			right--
			for right >= 0 {
				if !usedMap[right] {
					heap.Push(&pq2, &Item{
						value:    right,
						priority: costs[right],
						index:    rMin.index,
					})
					break
				}
			}
		} else {
			res += int64(lMin.priority)
			usedMap[lMin.value] = true
			pq1.Pop()
			fmt.Println("selecting", lMin.priority, "from pq1")
			left++
			for left < n {
				if !usedMap[left] {
					pq1.Push(&Item{
						value:    left,
						priority: costs[left],
						index:    lMin.index,
					})
					break
				}
				left++
			}
			// the value also on the right part
			if lMin.value >= right {
				fmt.Println("also selecting", rMin.priority, "from pq2")
				heap.Pop(&pq2)
				right--
				for right >= 0 {
					if !usedMap[right] {
						heap.Push(&pq2, &Item{
							value:    right,
							priority: costs[right],
							index:    rMin.index,
						})
						break
					}
					right--
				}
			}
		}
		count++
	}
	for count < k && pq1.Len() > 0 {
		res += int64(pq1[0].priority)
		fmt.Println(pq1[0].priority)
		heap.Pop(&pq1)
		count++
	}
	return res
}

func main() {
	costs := []int{28, 35, 21, 13, 21, 72, 35, 52, 74, 92, 25, 65, 77, 1, 73, 32, 43, 68, 8, 100, 84, 80, 14, 88, 42, 53, 98, 69, 64, 40, 60, 23, 99, 83, 5, 21, 76, 34}
	k := 32
	candidate := 12
	fmt.Println(totalCost(costs, k, candidate))
}
