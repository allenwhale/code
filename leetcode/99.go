package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func checkLeft(root *TreeNode) *TreeNode {
	cur := root
	var res, last *TreeNode
	for cur != nil {
		if cur.Left == nil {
			if last != nil && cur.Val <= last.Val {
				res = cur
			}
			cur, last = cur.Right, cur
		} else {
			tmp := cur.Left
			for tmp.Right != nil && tmp.Right != cur {
				tmp = tmp.Right
			}
			if tmp.Right == cur {
				tmp.Right = nil
				if last != nil && cur.Val <= last.Val {
					res = cur
				}
				cur, last = cur.Right, cur
			} else {
				tmp.Right = cur
				cur = cur.Left
			}
		}
	}
	return res
}
func checkRight(root *TreeNode) *TreeNode {
	cur := root
	var res, last *TreeNode
	for cur != nil {
		if cur.Right == nil {
			if last != nil && cur.Val >= last.Val {
				res = cur
			}
			cur, last = cur.Left, cur
		} else {
			tmp := cur.Right
			for tmp.Left != nil && tmp.Left != cur {
				tmp = tmp.Left
			}
			if tmp.Left == cur {
				tmp.Left = nil
				if last != nil && cur.Val >= last.Val {
					res = cur
				}
				cur, last = cur.Left, cur
			} else {
				tmp.Left = cur
				cur = cur.Right
			}
		}
	}
	return res
}

func recoverTree(root *TreeNode) {
	t1, t2 := checkLeft(root), checkRight(root)
	t1.Val, t2.Val = t2.Val, t1.Val
}

func print(root *TreeNode) {
	if root == nil {
		return
	}
	print(root.Left)
	fmt.Println(root, root.Val)
	print(root.Right)
}

func main() {
	// root := &TreeNode{Val: 1, Left: &TreeNode{Val: 3, Right: &TreeNode{Val: 2}}}
	root := &TreeNode{Val: 3, Left: &TreeNode{Val: 1}, Right: &TreeNode{Val: 4, Left: &TreeNode{Val: 2}}}
	recoverTree(root)
	print(root)
}
