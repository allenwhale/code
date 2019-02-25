package main

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	N, M := len(matrix), len(matrix[0])
	dp := make([][]int, N+1)
	for i := 0; i <= N; i = i + 1 {
		dp[i] = make([]int, M+1)
	}
	ans := 0
	for i := 1; i <= N; i = i + 1 {
		for j := 1; j <= M; j = j + 1 {
			if matrix[i-1][j-1] == '1' {
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1
				if ans < dp[i][j] {
					ans = dp[i][j]
				}
			}
		}
	}
	return ans * ans
}
func main() {

}
