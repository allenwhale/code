package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}
type BSTIterator struct {
	node *TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	return BSTIterator{
		node: root,
	}
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	res := -1
	cur := this.node
	for cur != nil {
		if cur.Left != nil {
			tmp := cur.Left
			for tmp.Right != cur && tmp.Right != nil {
				tmp = tmp.Right
			}
			if tmp.Right == cur {
				tmp.Right = nil
				res = cur.Val
				cur = cur.Right
				break
			} else {
				tmp.Right = cur
				cur = cur.Left
			}
		} else {
			res = cur.Val
			cur = cur.Right
			break
		}
	}
	this.node = cur
	return res
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return this.node != nil
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
func main() {

}
