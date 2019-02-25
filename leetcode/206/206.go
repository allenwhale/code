package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	cur := &ListNode{Next: head}
	head = cur
	prv := head.Next
	cur = prv.Next
	for cur != nil {
		head.Next, cur.Next, prv.Next = cur, head.Next, prv.Next.Next
		cur = prv.Next
	}
	return head.Next
}
func main() {

}
