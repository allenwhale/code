package main

import "fmt"

func dfs(s, l, side, left int, nums []int, dp, vis []bool) bool {
	if vis[s] {
		return dp[s]
	}
	if left == 0 {
		left = side
	}
	vis[s] = true
	for i := 0; i < l; i++ {
		if s&(1<<uint(i)) != 0 {
			if nums[i] <= left {
				if dfs(s^(1<<uint(i)), l, side, left-nums[i], nums, dp, vis) {
					dp[s] = true
					break
				}
			}
		}
	}
	return dp[s]
}

func makesquare(nums []int) bool {
	if len(nums) == 0 {
		return false
	}
	dp := make([]bool, 1<<uint(len(nums)))
	vis := make([]bool, 1<<uint(len(nums)))
	vis[0], dp[0] = true, true
	sum := 0
	for _, v := range nums {
		sum = sum + v
	}
	if sum%4 != 0 {
		return false
	}
	side := sum / 4
	return dfs((1<<uint(len(nums)))-1, len(nums), side, side, nums, dp, vis)
}
func main() {
	fmt.Println(makesquare([]int{1, 1, 2, 2, 2}))
}
