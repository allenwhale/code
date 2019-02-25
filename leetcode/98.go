package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(l, r int, root *TreeNode) bool {
	return root == nil || (l <= root.Val && root.Val <= r && dfs(l, root.Val-1, root.Left) && dfs(root.Val+1, r, root.Right))
}

func isValidBST(root *TreeNode) bool {
	return dfs(math.MinInt32, math.MaxInt32, root)
}
func main() {}
