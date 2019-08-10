package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func calculateMinimumHP(dungeon [][]int) int {
	R, C := len(dungeon), len(dungeon[0])
	for i := R - 1; i >= 0; i-- {
		for j := C - 1; j >= 0; j-- {
			if i == R-1 && j == C-1 {
			} else if i == R-1 {
				dungeon[i][j] = dungeon[i][j] + dungeon[i][j+1]
			} else if j == C-1 {
				dungeon[i][j] = dungeon[i][j] + dungeon[i+1][j]
			} else {
				dungeon[i][j] = dungeon[i][j] + max(dungeon[i][j+1], dungeon[i+1][j])
			}
			if dungeon[i][j] > 0 {
				dungeon[i][j] = 0
			}
		}
	}
	if dungeon[0][0] <= 0 {
		return 1 - dungeon[0][0]
	}
	return 0
}
func main() {

}
