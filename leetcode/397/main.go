package main

import "fmt"

var L = 10000

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func dfs(x int, dp map[int]int) int {
	if x == 1 {
		return 0
	}
	if v, ok := dp[x]; ok {
		return v
	}
	res := 0
	if x%2 == 0 {
		res = dfs(x/2, dp) + 1
	} else {
		res = min(dfs(x+1, dp), dfs(x-1, dp)) + 1
	}
	if x < L {
		dp[x] = res
	}
	return res
}
func integerReplacement(n int) int {
	dp := make(map[int]int, min(L, n))
	return dfs(n, dp)
}
func main() {
	fmt.Println(integerReplacement(100000000))
}
