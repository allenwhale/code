package main

var dx = []int{0, 0, 1, -1}
var dy = []int{1, -1, 0, 0}
var R, C int

func isin(x, y int) bool {
	return x >= 0 && x < R && y >= 0 && y < C
}
func dfs(x, s int, grid, dp [][]int, vis [][]bool) int {
	if vis[x][s] {
		return dp[x][s]
	}
	vis[x][s] = true
	dp[x][s] = 0
	i, j := x/C, x%C
	for k := 0; k < 4; k++ {
		ii, jj := i+dx[k], j+dy[k]
		ij := ii*C + jj
		if isin(ii, jj) && grid[ii][jj] != -1 && s&(1<<uint(ij)) != 0 {
			dp[x][s] = dp[x][s] + dfs(ij, s^(1<<uint(ij)), grid, dp, vis)
		}
	}
	return dp[x][s]
}

func uniquePathsIII(grid [][]int) int {
	R, C = len(grid), len(grid[0])
	n := R * C
	dp := make([][]int, n)
	vis := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, 1<<uint(n))
		vis[i] = make([]bool, 1<<uint(n))
	}
	s, sx, sy, ex, ey := 0, -1, -1, -1, -1
	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			if grid[i][j] != -1 {
				s = s | (1 << uint(i*C+j))
			}
			if grid[i][j] == 1 {
				sx, sy = i, j
			}
			if grid[i][j] == 2 {
				ex, ey = i, j
			}
		}
	}
	vis[ex*C+ey][0] = true
	dp[ex*C+ey][0] = 1
	return dfs(sx*C+sy, s^(1<<uint(sx*C+sy)), grid, dp, vis)
}
func main() {

}
