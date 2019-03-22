package main

import (
	"fmt"
)

func dfs(s, n, mx int, dp, vis []bool) bool {
	if n <= 0 {
		return false
	}
	// fmt.Println(s, n)
	if vis[s] {
		return dp[s]
	}
	vis[s] = true
	for i := 0; i < mx; i++ {
		if s&(1<<uint(i)) != 0 {
			if !dfs(s^(1<<uint(i)), n-i-1, mx, dp, vis) {
				dp[s] = true
				break
			}
		}
	}
	// fmt.Println(s, n, dp[s][n])
	return dp[s]
}

func canIWin(maxChoosableInteger int, desiredTotal int) bool {
	if desiredTotal == 0 {
		return true
	}
	if (maxChoosableInteger*(maxChoosableInteger+1))/2 < desiredTotal {
		return false
	}
	dp := make([]bool, 1<<uint(maxChoosableInteger))
	vis := make([]bool, 1<<uint(maxChoosableInteger))

	return dfs(1<<uint(maxChoosableInteger)-1, desiredTotal, maxChoosableInteger, dp, vis)
}
func main() {
	fmt.Println(canIWin(10, 11))
	// fmt.Println(canIWin(10, 11))
}
