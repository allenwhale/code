package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dfs(r *TreeNode) (bool, int) {
	if r == nil {
		return true, 0
	}
	b1, i1 := dfs(r.Left)
	b2, i2 := dfs(r.Right)
	return b1 && b2 && abs(i1-i2) <= 1, max(i1, i2) + 1
}

func isBalanced(root *TreeNode) bool {
	ans, _ := dfs(root)
	return ans
}
func main() {}
