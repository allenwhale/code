package main

import (
	"fmt"
	"math"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0
	for _, c := range coins {
		for i := c; i <= amount; i++ {
			dp[i] = min(1+dp[i-c], dp[i])
		}
	}
	if dp[amount] == math.MaxInt32 {
		return -1
	}
	return dp[amount]
}
func main() {
	fmt.Println(coinChange([]int{1, 2, 5}, 11))
}
