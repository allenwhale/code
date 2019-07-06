package main

import "fmt"

func lastStoneWeightII(stones []int) int {
	dp, sum := [3010]bool{}, 0
	dp[0] = true
	for _, v := range stones {
		sum = sum + v
		for i := 3000 - v; i >= 0; i-- {
			dp[i+v] = dp[i+v] || dp[i]
		}
	}
	ans := 3000
	for i := 0; i <= sum/2; i++ {
		if dp[i] && dp[sum-i] {
			if ans > sum-i-i {
				ans = sum - i - i
			}
		}
	}
	return ans
}
func main() {
	fmt.Println(lastStoneWeightII([]int{2, 7, 4, 1, 8, 1}))
}
