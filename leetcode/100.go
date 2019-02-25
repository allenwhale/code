package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hash(r *TreeNode) uint64 {
	if r == nil {
		return 0
	}
	return (hash(r.Left)^uint64(r.Val))*131 + hash(r.Right) + 1
}
func isSameTree(p *TreeNode, q *TreeNode) bool {
	return hash(p) == hash(q)
}
func main() {}
