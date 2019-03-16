package main

import (
	"fmt"
	"math"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func findMin(nums []int) int {
	if len(nums) == 0 {
		return math.MaxInt32
	}
	if len(nums) == 1 {
		return nums[0]
	}
	if len(nums) == 2 {
		return min(nums[0], nums[1])
	}
	if nums[0] < nums[len(nums)-1] {
		return nums[0]
	}
	mid := len(nums) / 2
	return min(findMin(nums[:mid]), findMin(nums[mid:]))
}
func main() {
	fmt.Println(findMin([]int{3, 4, 5, 1, 2}))
}
