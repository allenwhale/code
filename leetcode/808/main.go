package main

import "fmt"

func dfs(a, b int, dp []float64, vis []bool) float64 {
	if a <= 0 && b > 0 {
		return 1.0
	}
	if a <= 0 && b <= 0 {
		return 0.5
	}
	if a > 0 && b <= 0 {
		return 0.
	}
	if vis[a*200+b] {
		return dp[a*200+b]
	}
	vis[a*200+b] = true

	dp[a*200+b] = (dfs(a-4, b, dp, vis) +
		dfs(a-3, b-1, dp, vis) +
		dfs(a-2, b-2, dp, vis) +
		dfs(a-1, b-3, dp, vis)) / 4.
	return dp[a*200+b]
}
func soupServings(N int) float64 {
	if N >= 4000 {
		return 1.
	}
	N = (N + 24) / 25
	dp := make([]float64, 200*200)
	vis := make([]bool, 200*200)
	return dfs(N, N, dp, vis)
}
func main() {
	var N int
	for true {
		fmt.Scanf("%d", &N)
		fmt.Println(soupServings(N))
	}
}
