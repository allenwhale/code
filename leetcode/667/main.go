package main

import "fmt"

func constructArray(n int, k int) []int {
	res := make([]int, n)
	res[0] = 1
	for i, f := k, 1; i >= 1; i, f = i-1, f*-1 {
		res[k-i+1] = res[k-i] + f*i
		// res = append(res, res[len(res)-1]+f*i)
	}
	for i := k + 2; i <= n; i++ {
		// res = append(res, i)
		res[i-1] = i
	}
	return res
}
func main() {
	fmt.Println(constructArray(5, 3))
}
