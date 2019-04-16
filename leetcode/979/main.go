package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func dfs(tr *TreeNode) (int, int, int) {
	if tr == nil {
		return 0, 0, 0
	}
	lsum, lch, lans := dfs(tr.Left)
	rsum, rch, rans := dfs(tr.Right)
	ans := abs(lsum-lch) + abs(rsum-rch)

	return lsum + rsum + tr.Val, lch + rch + 1, lans + rans + ans
}

func distributeCoins(root *TreeNode) int {
	_, _, ans := dfs(root)
	return ans
}
func main() {

}
