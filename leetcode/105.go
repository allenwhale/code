package main

// import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(preorder *[]int, inorder []int, a, b int, m map[int]int) *TreeNode {
	if a > b {
		return nil
	}
	r := &TreeNode{Val: (*preorder)[0]}
	*preorder = (*preorder)[1:]
	r.Left = dfs(preorder, inorder, a, m[r.Val]-1, m)
	r.Right = dfs(preorder, inorder, m[r.Val]+1, b, m)
	return r
}
func buildTree(preorder []int, inorder []int) *TreeNode {
	m := make(map[int]int)
	for i, x := range inorder {
		m[x] = i
	}
	return dfs(&preorder, inorder, 0, len(inorder)-1, m)
}
func main() {
	buildTree([]int{3, 9, 20, 15, 7}, []int{9, 3, 15, 20, 7})
}
