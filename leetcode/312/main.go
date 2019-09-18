package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func dfs(dp [][]int, nums []int, left, right int) int {
	if dp[left][right] != -1 {
		return dp[left][right]
	}
	if left+1 == right {
		dp[left][right] = 0
		return 0
	}
	for i := left + 1; i < right; i++ {
		dp[left][right] = max(dp[left][right], dfs(dp, nums, left, i)+dfs(dp, nums, i, right)+nums[i]*nums[left]*nums[right])
	}
	return dp[left][right]
}
func maxCoins(nums []int) int {
	n := len(nums)
	nums = append(append([]int{1}, nums...), 1)
	dp := make([][]int, n+2)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, n+2)
		for j := 0; j < n+2; j++ {
			dp[i][j] = -1
		}
	}
	return dfs(dp, nums, 0, n+1)
}
func main() {
	fmt.Println(maxCoins([]int{3, 1, 5, 8}))
}
