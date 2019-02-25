package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func indexOf(a []int, x int) int {
	for i, y := range a {
		if x == y {
			return i
		}
	}
	return -1
}

func buildTree(inorder, postorder []int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}
	idx := indexOf(inorder, postorder[len(postorder)-1])
	r := &TreeNode{Val: postorder[len(postorder)-1]}
	r.Right = buildTree(inorder[idx+1:], postorder[:len(postorder)-1])
	r.Left = buildTree(inorder[:idx], postorder[:len(postorder)-len(inorder)+idx])
	return r
}
func main() {
	buildTree([]int{9, 3, 15, 20, 7}, []int{9, 15, 7, 20, 3})
}
