package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func toArray(tr *TreeNode, arr *[]int) {
	if tr == nil {
		return
	}
	toArray(tr.Left, arr)
	*arr = append(*arr, tr.Val)
	toArray(tr.Right, arr)
}

func findTarget(root *TreeNode, k int) bool {
	arr := make([]int, 0)
	toArray(root, &arr)
	mp := make(map[int]bool)
	for _, x := range arr {
		if _, ok := mp[k-x]; ok {
			return true
		}
		mp[x] = true
	}
	return false
}
func main() {

}
