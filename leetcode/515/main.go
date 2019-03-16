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
func dfs(tr *TreeNode, d int, ans *[]int) {
	if tr == nil {
		return
	}
	if d > len(*ans) {
		*ans = append(*ans, tr.Val)
	} else {
		(*ans)[d-1] = max((*ans)[d-1], tr.Val)
	}
	dfs(tr.Left, d+1, ans)
	dfs(tr.Right, d+1, ans)
}
func largestValues(root *TreeNode) []int {
	ans := make([]int, 0)
	dfs(root, 1, &ans)
	return ans
}
func main() {

}
