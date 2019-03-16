package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func dfs(tr *TreeNode, last, ans *int) {
	if tr == nil {
		return
	}
	dfs(tr.Left, last, ans)
	*ans = min(*ans, tr.Val-*last)
	*last = tr.Val
	dfs(tr.Right, last, ans)
}
func minDiffInBST(root *TreeNode) int {
	last, ans := math.MinInt32, math.MaxInt32
	dfs(root, &last, &ans)
	return ans
}
func main() {

}
