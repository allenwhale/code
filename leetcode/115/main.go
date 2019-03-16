package main

import (
	"fmt"
)

func numDistinct(s string, t string) int {
	dp := make([][]int, len(s)+1)
	for i := 0; i <= len(s); i++ {
		dp[i] = make([]int, len(t)+1)
	}
	for i := 0; i <= len(t); i++ {
		dp[0][i] = 0
	}
	for i := 0; i <= len(s); i++ {
		dp[i][0] = 1
	}

	for i := 0; i < len(s); i++ {
		for j := 0; j < len(t); j++ {
			if s[i] == t[j] {
				dp[i+1][j+1] = dp[i][j] + dp[i][j+1]
			} else {
				dp[i+1][j+1] = dp[i][j+1]
			}
		}
	}
	// pretty.Println(dp)
	return dp[len(s)][len(t)]
}
func main() {
	fmt.Println(numDistinct("bbb", "bb"))
	fmt.Println(numDistinct("rabbbit", "rabbit"))
}
