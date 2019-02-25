package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Itoa(x int) []byte {
	if x == 0 {
		return []byte("0")
	}
	sgn := 1
	if x < 0 {
		sgn, x = -1, -x
	}
	res := []byte{}
	for x > 0 {
		res, x = append([]byte{byte(x%10) + byte('0')}, res...), x/10
	}
	if sgn == -1 {
		res = append([]byte{'-'}, res...)
	}
	return res
}

func dfs(t *TreeNode, now []byte, ans *[]string) {
	now = append(append(now, []byte("->")...), Itoa(t.Val)...)
	if t.Left == nil && t.Right == nil {
		*ans = append(*ans, string(now))
		return
	}
	if t.Left != nil {
		dfs(t.Left, now, ans)
	}
	if t.Right != nil {
		dfs(t.Right, now, ans)
	}
}

func binaryTreePaths(root *TreeNode) []string {
	if root == nil {
		return []string{}
	}
	if root.Left == nil && root.Right == nil {
		return []string{string(Itoa(root.Val))}
	}
	now, ans := Itoa(root.Val), []string{}
	if root.Left != nil {
		dfs(root.Left, now, &ans)
	}
	if root.Right != nil {
		dfs(root.Right, now, &ans)
	}
	return ans
}
func main() {

}
