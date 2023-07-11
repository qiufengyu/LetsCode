package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	q := make([](*TreeNode), 0)
	res := 0
	if root != nil {
		q = append(q, root)
		for len(q) > 0 {
			res++
			sz := len(q)
			for sz > 0 {
				node := q[0]
				q = q[1:]
				if node.Left == nil && node.Right == nil {
					return res
				} else {
					if node.Left != nil {
						q = append(q, node.Left)
					}
					if node.Right != nil {
						q = append(q, node.Right)
					}
				}
				sz--
			}
		}
	}
	return res
}
