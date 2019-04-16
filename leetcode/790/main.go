package main

import (
	"fmt"
)

const mod = int64(1e9 + 7)

func numTilings(N int) int {
	dp := make([][]int64, 2)
	dp[0] = make([]int64, N+1)
	dp[1] = make([]int64, N+1)
	dp[0][0], dp[0][1] = int64(1), int64(1)
	for i := 2; i <= N; i++ {
		dp[0][i] = (dp[0][i-1] + dp[0][i-2] + dp[1][i-1]) % mod
		dp[1][i] = (2*dp[0][i-2] + dp[1][i-1]) % mod
	}
	// pretty.Println(dp)
	return int(dp[0][N])
}
func main() {
	fmt.Println(numTilings(3))
	fmt.Println(numTilings(4))
	fmt.Println(numTilings(5))
}
