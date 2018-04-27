package main
import "github.com/kr/pretty"

type ListNode struct {
	Val int
	Next *ListNode
}
func rotateRight(head *ListNode, k int) *ListNode {
    if head == nil {
        return nil
    }
    prehead := &ListNode{Next: head}
    cur, l := prehead, 0
    for cur.Next != nil {
        cur, l = cur.Next, l + 1
    }
    cur.Next = head
    k %= l
    if k != 0 {
        for i := 0 ; i < l - k ; i++ {
            cur = cur.Next
        }
    }
    head, cur.Next = cur.Next, nil
    return head
}

func main() {
}
