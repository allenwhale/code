package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	ans, mn := 0, prices[0]
	for _, p := range prices[1:] {
		ans = max(ans, p-mn)
		mn = min(mn, p)
	}
	return ans
}
func main() {
	fmt.Println(maxProfit([]int{7, 1, 5, 3, 6, 4}))
}
