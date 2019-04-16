package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func addOneRow(root *TreeNode, v int, d int) *TreeNode {
	if root == nil {
		return root
	}
	if d == 1 {
		root = &TreeNode{Val: v, Left: root}
	} else if d == 2 {
		L, R := root.Left, root.Right
		root.Left = &TreeNode{Val: v, Left: L}
		root.Right = &TreeNode{Val: v, Right: R}
	} else {
		root.Left = addOneRow(root.Left, v, d-1)
		root.Right = addOneRow(root.Right, v, d-1)
	}
	return root
}
func main() {

}
