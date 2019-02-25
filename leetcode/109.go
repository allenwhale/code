package main

type ListNode struct {
	Val  int
	Next *ListNode
}
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func build(a []int) *TreeNode {
	if len(a) == 0 {
		return nil
	}
	mid := len(a) / 2
	return &TreeNode{Val: a[mid], Left: build(a[:mid]), Right: build(a[mid+1:])}
}

func sortedListToBST(head *ListNode) *TreeNode {
	a := []int{}
	for head != nil {
		a, head = append(a, head.Val), head.Next
	}
	return build(a)
}
func main() {}
