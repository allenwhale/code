package main

import "fmt"

var P = []int64{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func countDigitOne(n int) int {

	nn, res, i := int64(n), int64(0), 0
	for nn >= P[i] {
		res = res + nn/P[i+1]*P[i] + min(P[i], max(nn%P[i+1]-P[i]+1, int64(0)))
		i++
	}
	return int(res)
}
func main() {
	fmt.Println(countDigitOne(100))
}
