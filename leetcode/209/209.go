package main

import (
	"fmt"
	"math"
)

func minSubArrayLen(s int, nums []int) int {
	now, ans := 0, math.MaxInt32
	for i, r := 0, 0; i < len(nums); i += 1 {
		for r < len(nums) && now < s {
			now, r = now+nums[r], r+1
		}
		if now >= s && r-i < ans {
			ans = r - i
		}
		now = now - nums[i]
	}
	if ans != math.MaxInt32 {
		return ans
	}
	return 0
}
func main() {
	fmt.Println(minSubArrayLen(7, []int{2, 3, 1, 2, 4, 3}))
}
