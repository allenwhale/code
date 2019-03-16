package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func findLHS(nums []int) int {
	mp, ans := make(map[int]int), 0
	for _, v := range nums {
		mp[v] = mp[v] + 1
	}
	for k := range mp {
		if mp[k-1] != 0 {
			ans = max(ans, mp[k]+mp[k-1])
		}
	}
	return ans
}
func main() {
	fmt.Println(findLHS([]int{1, 2, 3, 4}))
}
