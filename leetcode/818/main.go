package main

import (
	"fmt"
	"math"
)

/*
 * @lc app=leetcode id=818 lang=golang
 *
 * [818] Race Car
 */
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func getK(a int) int {
	res := 1
	for a >= (1 << uint(res)) {
		res = res + 1
	}
	return res
}
func racecar(target int) int {
	dp := make([]int, target+1)
	dp[0] = 0
	for i := 1; i <= target; i++ {
		k := getK(i)
		if i == (1<<uint(k))-1 {
			dp[i] = k
		} else {
			dp[i] = math.MaxInt32
			for j := 0; j < k; j++ {
				dp[i] = min(dp[i], k-1+j+2+dp[i-(((1<<uint(k-1))-1)-((1<<uint(j))-1))])
			}
			dp[i] = min(dp[i], dp[1<<uint(k)-1-i]+k+1)
		}
	}
	return dp[target]
}

func main() {
	fmt.Println(racecar(10))
}
