package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func print(head *ListNode) {
	for head != nil {
		fmt.Println(head.Val)
		head = head.Next
	}
}
func isPalindrome(head *ListNode) bool {
	if head == nil {
		return true
	}
	len, cur := 0, head
	for cur != nil {
		len, cur = len+1, cur.Next
	}
	if len == 1 {
		return true
	} else if len == 2 {
		return head.Val == head.Next.Val
	} else {
		mid := len / 2
		cur, nxt := &ListNode{Next: head}, head
		for i := 0; i < mid-1; i = i + 1 {
			cur.Next, nxt.Next.Next, nxt.Next = nxt.Next, cur.Next, nxt.Next.Next
		}
		head, nxt = cur.Next, nxt.Next
		if len%2 == 1 {
			nxt = nxt.Next
		}
		for i := 0; i < mid; i = i + 1 {
			if head.Val != nxt.Val {
				return false
			}
			head, nxt = head.Next, nxt.Next
		}
		return true
	}
}
func main() {
	head := &ListNode{Val: 0, Next: &ListNode{Val: 0, Next: &ListNode{Val: 1, Next: &ListNode{Val: 0}}}}
	fmt.Println(isPalindrome(head.Next))
}
