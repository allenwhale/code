package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minCut(s string) int {
	c0 := make([]bool, len(s))
	c1 := make([]bool, len(s))
	dp := make([]int, len(s)+1)
	dp[0] = 0
	dp[1] = 1
	for i := 1; i < len(s); i++ {
		dp[i+1] = dp[i] + 1
		for j := i - 1; ; j-- {
			//1
			if 2*j+1-i < 0 {
				break
			}
			if s[2*j+1-i] != s[i] {
				c1[j] = true
			}
			if !c1[j] {
				dp[i+1] = min(dp[i+1], dp[2*j+1-i]+1)
			}
			//0
			if 2*j-i < 0 {
				break
			}
			if s[2*j-i] != s[i] {
				c0[j] = true
			}
			if !c0[j] {
				dp[i+1] = min(dp[i+1], dp[2*j-i]+1)
			}
		}
	}
	return dp[len(s)] - 1
}
func main() {
	fmt.Println(minCut("aab"))
}
