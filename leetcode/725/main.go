package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func splitListToParts(root *ListNode, k int) []*ListNode {
	res := make([]*ListNode, k)
	curr := make([]*ListNode, k)
	for i := 0; i < k; i++ {
		res[i] = &ListNode{}
		curr[i] = res[i]
	}
	n, c := 0, root
	for c != nil {
		n, c = n+1, c.Next
	}
	e, r := n/k, n-(n/k)*k
	for i := 0; i < k; i++ {
		ee := e
		if i < r {
			ee++
		}
		for j := 0; j < ee; j++ {
			curr[i].Next = &ListNode{Val: root.Val}
			curr[i] = curr[i].Next
			root = root.Next
		}
	}
	for i := 0; i < k; i++ {
		res[i] = res[i].Next
	}
	return res
}
func main() {

}
