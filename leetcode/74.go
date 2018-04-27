package main

import (
	"github.com/kr/pretty"
)

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	n, m := len(matrix), len(matrix[0])
	l, r := 0, n*m-1
	for l <= r {
		mid := (l + r) >> 1
		mx, my := mid/m, mid%m
		if matrix[mx][my] == target {
			return true
		} else if matrix[mx][my] < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return false
}

func main() {
	searchMatrix([][]int{{1, 3}}, 3)
}
