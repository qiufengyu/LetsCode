package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func allPossibleFBT(n int) []*TreeNode {
	if n%2 == 0 {
		return []*TreeNode{}
	}
	m := make(map[int]([]*TreeNode))
	helper(n, m)
	return m[n]
}

func helper(n int, memo map[int]([]*TreeNode)) []*TreeNode {
	if n == 1 {
		memo[1] = []*TreeNode{{Val: 0, Left: nil, Right: nil}}
		return memo[1]
	}
	if _, ok := memo[n]; ok {
		return memo[n]
	}
	res := make([]*TreeNode, 0)
	for i := 1; i < n; i += 2 {
		l := helper(i, memo)
		r := helper(n-i-1, memo)
		for li := 0; li < len(l); li++ {
			for ri := 0; ri < len(r); ri++ {
				root := &TreeNode{
					Val: 0, Left: l[li], Right: r[ri],
				}
				res = append(res, root)
			}
		}
	}
	memo[n] = res
	return res
}
