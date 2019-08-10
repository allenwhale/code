package main

import (
	"fmt"
	"math"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maxProfit(k int, prices []int) int {
	if k == 0 {
		return 0
	}
	if k >= (len(prices)+1)/2 {
		k = (len(prices) + 1) / 2
	}
	h0 := make([]int, k+1)
	h1 := make([]int, k+1)
	for i := 0; i <= k; i++ {
		h0[i], h1[i] = math.MinInt32, math.MinInt32
	}
	h0[0] = 0
	for _, v := range prices {
		h0[k] = max(h0[k], h1[k-1]+v)
		for i := k - 1; i > 0; i-- {
			h1[i] = max(h1[i], h0[i]-v)
			h0[i] = max(h0[i], h1[i-1]+v)
		}
		h1[0] = max(h1[0], -v)
	}
	ans := math.MinInt32
	for i := 0; i <= k; i++ {
		ans = max(ans, h0[i])
	}
	return ans
}
func main() {
	fmt.Println(maxProfit(2, []int{2, 4, 1}))
	fmt.Println(maxProfit(2, []int{3, 2, 6, 5, 0, 3}))
}
