package main

type Stat struct {
	i, j int
}

var (
	dx = []int{0, 0, 1, -1}
	dy = []int{1, -1, 0, 0}
	R  = 0
	C  = 0
)

func isin(i, j int) bool {
	return i >= 0 && i < R && j >= 0 && j < C
}

func numIslands(grid [][]byte) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	R, C = len(grid), len(grid[0])
	ans := 0
	for i := 0; i < R; i = i + 1 {
		for j := 0; j < C; j = j + 1 {
			if grid[i][j] == '1' {
				ans = ans + 1
				grid[i][j] = 0
				queue := []Stat{Stat{i: i, j: j}}
				for len(queue) != 0 {
					n := queue[0]
					queue = queue[1:]
					for k := 0; k < 4; k = k + 1 {
						ii, jj := n.i+dx[k], n.j+dy[k]
						if isin(ii, jj) && grid[ii][jj] == '1' {
							queue = append(queue, Stat{i: ii, j: jj})
							grid[ii][jj] = 0
						}
					}
				}
			}
		}
	}
	return ans
}
func main() {

}
