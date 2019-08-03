package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func dfs(root *TreeNode) (int, int) {
	max, left, right := root.Val, root.Val, root.Val
	if root.Left != nil {
		nm, nlr := dfs(root.Left)
		left = Max(left, nlr+root.Val)
		max = Max(max, Max(nm, left))
	}
	if root.Right != nil {
		nm, nlr := dfs(root.Right)
		right = Max(right, nlr+root.Val)
		max = Max(max, Max(nm, right))
	}
	max = Max(max, left+right-root.Val)
	return max, Max(left, right)
}
func maxPathSum(root *TreeNode) int {
	ans, _ := dfs(root)
	return ans
}
func main() {

}
