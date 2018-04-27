package main

import (
	"github.com/kr/pretty"
)

var (
	dx = []int{0, 0, 1, -1}
	dy = []int{1, -1, 0, 0}
)

func isIn(x, y int, board [][]byte) bool {
	return x >= 0 && y >= 0 && x < len(board) && y < len(board[0])
}

func dfs(x, y, idx int, s string, board [][]byte) bool {
	if idx == len(s) {
		return true
	}
	for i := 0; i < 4; i++ {
		tx, ty := x+dx[i], y+dy[i]
		if isIn(tx, ty, board) && board[tx][ty] == s[idx] {
			board[tx][ty] = 0
			if dfs(tx, ty, idx+1, s, board) {
				return true
			}
			board[tx][ty] = s[idx]
		}
	}
	return false
}

func exist(board [][]byte, word string) bool {
	n, m := len(board), len(board[0])
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if board[i][j] == word[0] {
				board[i][j] = 0
				if dfs(i, j, 1, word, board) {
					return true
				}
				board[i][j] = word[0]
			}
		}
	}
	return false
}
func main() {
	pretty.Println(exist([][]byte{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	}, "ABCCED"))
}
