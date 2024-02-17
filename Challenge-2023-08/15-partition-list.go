package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	l1, l2 := &ListNode{Val: 1, Next: nil}, &ListNode{Val: 1, Next: nil}
	cur, c1, c2 := head, l1, l2
	for cur != nil {
		if cur.Val < x {
			c1.Next = cur
			c1 = c1.Next
		} else {
			c2.Next = cur
			c2 = c2.Next
		}
		cur = cur.Next
	}
	c1.Next = l2.Next
	c2.Next = nil
	return l1.Next
}
