package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxDepth(r *TreeNode) int {
	if r == nil {
		return 0
	}
	return max(maxDepth(r.Left), maxDepth(r.Right)) + 1
}
func main() {}
