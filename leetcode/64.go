package main
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func minPathSum(grid [][]int) int {
    n, m := len(grid), len(grid[0])
    dp := make([][]int, n)
    for i := 0 ; i < n ; i++ {
        dp[i] = make([]int, m)
    }
    for i := 0 ; i < n ; i++ {
        for j := 0 ; j < m ; j++ {
            if i == 0 && j == 0 {
                dp[i][j] = grid[i][j]
            } else if i == 0 {
                dp[i][j] = dp[i][j - 1] + grid[i][j]
            } else if j == 0 {
                dp[i][j] = dp[i - 1][j] + grid[i][j]
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
            }
        }
    }
    return dp[n - 1][m - 1]
}
func main() {
}
