package main
import "github.com/kr/pretty"

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    n, m := len(obstacleGrid), len(obstacleGrid[0])
    dp := make([][]int, n + 1)
    for i := 0 ; i <= n ; i++ {
        dp[i] = make([]int, m + 1)
    }
    for i := 0 ; i < n ; i++ {
        for j := 0 ; j < m ; j++ {
            if i == 0 && j == 0 && obstacleGrid[0][0] == 0 {
                dp[1][1] = 1
            } else if obstacleGrid[i][j] == 0 {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j]
            }
        }
    }
    return dp[n][m]
}
func main() {
    uniquePathsWithObstacles([][]int{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    })
}
