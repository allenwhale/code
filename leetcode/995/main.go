package main

import "fmt"

func minKBitFlips(A []int, K int) int {
	f, end, ans := 1, []int{}, 0
	for i := 0; i < len(A)-K+1; i++ {
		if len(end) > 0 && end[0] == i {
			f, end = 1-f, end[1:]
		}
		if A[i] != f {
			ans, f, end = ans+1, 1-f, append(end, i+K)
		}
	}
	for i := len(A) - K + 1; i < len(A); i++ {
		if len(end) > 0 && end[0] == i {
			f, end = 1-f, end[1:]
		}
		if A[i] != f {
			return -1
		}
	}
	return ans
}
func main() {
	fmt.Println(minKBitFlips([]int{0, 1, 0}, 1))
	fmt.Println(minKBitFlips([]int{1, 1, 0}, 2))
	fmt.Println(minKBitFlips([]int{0, 0, 0, 1, 0, 1, 1, 0}, 3))
}
