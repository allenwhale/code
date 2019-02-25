package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	prv, cur := &ListNode{Val: head.Val - 1, Next: head}, head
	head = prv
	lastDup, Dup := 0, false
	for cur != nil {
		if !Dup {
			if cur.Next != nil && cur.Val == cur.Next.Val {
				lastDup = cur.Val
				prv.Next, cur = cur.Next, cur.Next
				Dup = true
			} else {
				prv, cur = cur, cur.Next
			}
		} else {
			if cur.Val == lastDup {
				prv.Next, cur = cur.Next, cur.Next
			} else {
				Dup = false
			}
		}
	}
	return head.Next
}

func print(head *ListNode) {
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
	fmt.Println()
}

func main() {
	head := &ListNode{Val: 1, Next: &ListNode{Val: 1, Next: nil}}
	print(head)
	head = deleteDuplicates(head)
	print(head)
}
