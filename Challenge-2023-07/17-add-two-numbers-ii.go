package main

type ListNode struct {
	Val  int
	Next *ListNode
}

type (
	Stack struct {
		top    *node
		length int
	}
	node struct {
		value interface{}
		prev  *node
	}
)

// Create a new stack
func NewStack() *Stack {
	return &Stack{nil, 0}
}

// Return the number of items in the stack
func (this *Stack) Len() int {
	return this.length
}

// View the top item on the stack
func (this *Stack) Peek() interface{} {
	if this.length == 0 {
		return nil
	}
	return this.top.value
}

// Pop the top item of the stack and return it
func (this *Stack) Pop() interface{} {
	if this.length == 0 {
		return nil
	}

	n := this.top
	this.top = n.prev
	this.length--
	return n.value
}

// Push a value onto the top of the stack
func (this *Stack) Push(value interface{}) {
	n := &node{value, this.top}
	this.top = n
	this.length++
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	s1, s2 := NewStack(), NewStack()
	n1, n2 := l1, l2
	for n1 != nil {
		s1.Push(n1.Val)
		n1 = n1.Next
	}
	for n2 != nil {
		s2.Push(n2.Val)
		n2 = n2.Next
	}
	carry, sum := 0, 0
	var result *ListNode = nil
	for s1.Len() > 0 && s2.Len() > 0 {
		sum = s1.Pop().(int) + s2.Pop().(int) + carry
		carry = sum / 10
		sum = sum % 10
		current := &ListNode{
			Val:  sum,
			Next: result,
		}
		result = current
	}
	for s1.Len() > 0 {
		sum = s1.Pop().(int) + carry
		carry = sum / 10
		sum = sum % 10
		current := &ListNode{
			Val:  sum,
			Next: result,
		}
		result = current
	}
	for s2.Len() > 0 {
		sum = s2.Pop().(int) + carry
		carry = sum / 10
		sum = sum % 10
		current := &ListNode{
			Val:  sum,
			Next: result,
		}
		result = current
	}
	if carry > 0 {
		current := &ListNode{
			Val:  carry,
			Next: result,
		}
		result = current
	}
	return result
}
