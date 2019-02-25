package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func generateTrees(n int) []*TreeNode {
	dp := make([][][]*TreeNode, n+2)
	for i := 0; i <= n+1; i += 1 {
		dp[i] = make([][]*TreeNode, n+2)
	}
	for i := 1; i <= n; i++ {
		dp[i][i] = append(dp[i][i], &TreeNode{Val: i})
	}
	for k := 2; k <= n; k += 1 {
		for i := 1; i+k-1 <= n; i += 1 {
			j := i + k - 1
			for l := i; l <= j; l += 1 {
				if len(dp[i][l-1]) == 0 {
					for _, x := range dp[l+1][j] {
						dp[i][j] = append(dp[i][j], &TreeNode{Val: l, Left: nil, Right: x})
					}
				} else if len(dp[l+1][j]) == 0 {
					for _, x := range dp[i][l-1] {
						dp[i][j] = append(dp[i][j], &TreeNode{Val: l, Left: x, Right: nil})
					}
				} else {
					for _, x := range dp[i][l-1] {
						for _, y := range dp[l+1][j] {
							dp[i][j] = append(dp[i][j], &TreeNode{Val: l, Left: x, Right: y})
						}
					}
				}
			}
		}
	}
	return dp[1][n]
}
func main() {}
