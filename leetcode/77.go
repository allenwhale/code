package main

import (
	_ "github.com/kr/pretty"
)

func dfs(x, n, k int, cur []int, ans *[][]int) {
	if k == 0 {
		*ans = append(*ans, append([]int(nil), cur...))
		return
	}
	if x == n+1 || n-x+1 < k {
		return
	}
	for i := x; i <= n; i++ {
		cur[k-1] = i
		dfs(i+1, n, k-1, cur, ans)
	}
}
func combine(n int, k int) [][]int {
	ans, cur := [][]int{}, make([]int, k)
	dfs(1, n, k, cur, &ans)
	return ans
}
func main() {
}
