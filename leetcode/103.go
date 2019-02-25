package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type stat struct {
	n *TreeNode
	d int
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	ans := [][]int(nil)
	queue := []stat(nil)
	queue = append(queue, stat{n: root, d: 0})
	for len(queue) != 0 {
		n, d := queue[0].n, queue[0].d
		queue = queue[1:]
		if n == nil {
			continue
		}
		if len(ans) <= d {
			ans = append(ans, []int(nil))
		}
		if d&1 == 0 {
			ans[d] = append(ans[d], n.Val)
		} else {
			ans[d] = append([]int{n.Val}, ans[d]...)
		}
		queue = append(queue, stat{n: n.Left, d: d + 1}, stat{n: n.Right, d: d + 1})
	}
	return ans
}
func main() {
	root := &TreeNode{Val: 1, Left: &TreeNode{Val: 0}, Right: &TreeNode{Val: 2}}
	fmt.Println(zigzagLevelOrder(root))
}
