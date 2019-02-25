package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func inorderTraversal(root *TreeNode) []int {
	ans := []int{}
	cur := root
	for cur != nil {
		if cur.Left != nil {
			tmp := cur.Left
			for tmp.Right != nil && tmp.Right != cur {
				tmp = tmp.Right
			}
			if tmp.Right == nil {
				tmp.Right = cur
				cur = cur.Left
			} else {
				tmp.Right = nil
				ans = append(ans, cur.Val)
				cur = cur.Right
			}
		} else {
			ans = append(ans, cur.Val)
			cur = cur.Right
		}
	}
	return ans
}
func main() {}
