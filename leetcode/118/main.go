package main

import (
	"github.com/kr/pretty"
)

func generate(numRows int) [][]int {
	if numRows == 0 {
		return [][]int{}
	}
	ans := make([][]int, 0, numRows)
	for i := 1; i <= numRows; i++ {
		tmp := make([]int, i)
		tmp[0], tmp[len(tmp)-1] = 1, 1
		for j := 1; j < i-1; j++ {
			tmp[j] = ans[len(ans)-1][j-1] + ans[len(ans)-1][j]
		}
		ans = append(ans, tmp)
	}
	return ans
}
func main() {
	pretty.Println(generate(5))
}
