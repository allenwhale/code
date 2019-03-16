package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	a, b := head, head
	for a != nil && b != nil {
		a = a.Next
		b = b.Next
		if b == nil {
			return false
		}
		b = b.Next
		if a == b {
			return true
		}
	}
	return false
}
func main() {
	head := &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 0, Next: &ListNode{Val: 4}}}}
	head.Next.Next.Next.Next = head
	fmt.Println(hasCycle(head))
}
