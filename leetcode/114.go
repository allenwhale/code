package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var prev *TreeNode

func _flatten(root *TreeNode) {
	if root == nil {
		return
	}
	_flatten(root.Right)
	_flatten(root.Left)
	root.Right, root.Left, prev = prev, nil, root
}
func flatten(root *TreeNode) {
	prev = nil
	_flatten(root)
}
func main() {}
