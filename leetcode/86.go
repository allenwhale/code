package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func partition(head *ListNode, x int) *ListNode {
	cur := head
	var l1, l2, r1, r2 *ListNode
	for cur != nil {
		if cur.Val < x {
			if l1 == nil {
				l1, l2 = cur, cur
			} else {
				l2.Next = cur
				l2 = l2.Next
			}
		} else {
			if r1 == nil {
				r1, r2 = cur, cur
			} else {
				r2.Next = cur
				r2 = r2.Next
			}
		}
		cur = cur.Next
	}
	if l1 == nil && r1 == nil {
		return nil
	} else if l1 == nil {
		r2.Next = nil
		return r1
	} else if r1 == nil {
		return l1
	} else {
		l2.Next = r1
		r2.Next = nil
		return l1
	}
}

func print(head *ListNode) {
	for head != nil {
		fmt.Printf("%d ", head.Val)
		head = head.Next
	}
	fmt.Println()
}
func main() {
	// 1->4->3->2->5->2
	head := &ListNode{Val: 1, Next: &ListNode{Val: 4, Next: &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 5, Next: &ListNode{Val: 2, Next: nil}}}}}}
	head = partition(head, 3)
	print(head)
}
