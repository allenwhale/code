package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func postorderTraversal(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	ans := postorderTraversal(root.Left)
	ans = append(ans, postorderTraversal(root.Right)...)
	return append(ans, root.Val)
}
func main() {

}
