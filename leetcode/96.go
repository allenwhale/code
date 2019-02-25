package main

import "github.com/kr/pretty"

func numTrees(n int) int {
	dp := make([]int, n+2)
	dp[0], dp[1] = 1, 1
	for k := 2; k <= n; k += 1 {
		for i := 0; i <= k-1; i += 1 {
			dp[k] += dp[i] * dp[k-1-i]
		}
	}
	return dp[n]
}

func main() {
	numTrees(3)
}
