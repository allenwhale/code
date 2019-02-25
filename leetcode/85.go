package main

import "fmt"

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	H := make([]int, len(matrix[0])+1)
	ans := 0
	for i := 0; i < len(matrix); i += 1 {
		matrix[i] = append(matrix[i], '0')
		for j := 0; j < len(matrix[0]); j += 1 {
			if matrix[i][j] == '0' {
				H[j] = 0
			} else {
				H[j] += 1
			}
		}
		stk, idx := []int(nil), 0
		for j := 0; j < len(matrix[0]); j += 1 {
			if len(stk) == 0 || H[stk[len(stk)-1]] <= H[j] {
				stk = append(stk, j)
			} else {
				for len(stk) != 0 && H[stk[len(stk)-1]] > H[j] {
					idx, stk = stk[len(stk)-1], stk[:len(stk)-1]
					if len(stk) == 0 {
						ans = Max(ans, H[idx]*j)
					} else {
						ans = Max(ans, H[idx]*(j-stk[len(stk)-1]-1))
					}
				}
				stk = append(stk, j)
			}
		}
	}
	return ans
}
func main() {
	matrix := [][]byte{
		[]byte{'1', '0', '1', '0', '0'},
		[]byte{'1', '0', '1', '1', '1'},
		[]byte{'1', '1', '1', '1', '1'},
		[]byte{'1', '0', '0', '1', '0'},
	}
	fmt.Println(maximalRectangle(matrix))

}
