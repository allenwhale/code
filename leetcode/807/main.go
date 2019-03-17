package main

import "math"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxIncreaseKeepingSkyline(grid [][]int) int {
	s1, s2 := make([]int, len(grid)), make([]int, len(grid[0]))
	for i := 0; i < len(grid); i++ {
		s1[i] = math.MinInt32
	}
	for i := 0; i < len(grid[0]); i++ {
		s2[i] = math.MinInt32
	}
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			s1[i] = max(s1[i], grid[i][j])
			s2[j] = max(s2[j], grid[i][j])
		}
	}
	ans := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			ans = ans + min(s1[i], s2[j]) - grid[i][j]
		}
	}
	return ans
}
func main() {

}
