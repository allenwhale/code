package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, sum int, tmp []int, ans *[][]int) {
	if root == nil {
		return
	}
	if root != nil && root.Val == sum && root.Left == nil && root.Right == nil {
		*ans = append(*ans, append([]int{}, append(tmp, root.Val)...))
		return
	}
	hasPathSum(root.Left, sum-root.Val, append(tmp, root.Val), ans)
	hasPathSum(root.Right, sum-root.Val, append(tmp, root.Val), ans)
}

func pathSum(root *TreeNode, sum int) [][]int {
	tmp, ans := []int{}, [][]int{}
	hasPathSum(root, sum, tmp, &ans)
	return ans
}
func main() {}
