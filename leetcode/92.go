package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func print(h *ListNode) {
	for h != nil {
		fmt.Printf("%d ", h.Val)
		h = h.Next
	}
	fmt.Println()
}

func reverseBetween(head *ListNode, m int, n int) *ListNode {
	prv, cur := &ListNode{Val: 0, Next: head}, head
	h := prv
	for i := 1; i < m; i += 1 {
		prv, cur = cur, cur.Next
	}
	// fmt.Println(prv.Val, cur.Val)
	nprv, ncur := prv.Next, cur.Next
	for i := 0; i < n-m; i += 1 {
		// fmt.Println("n", prv.Val, cur.Val, nprv.Val, ncur.Val)
		prv.Next, ncur.Next, nprv.Next = ncur, cur, ncur.Next
		cur, ncur = prv.Next, nprv.Next
		// print(h.Next)
	}
	return h.Next
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	head := &ListNode{Val: 0, Next: nil}
	cur := head
	for _, x := range arr {
		cur.Next = &ListNode{Val: x, Next: nil}
		cur = cur.Next
	}
	head = reverseBetween(head.Next, 1, 4)
	print(head)
}
