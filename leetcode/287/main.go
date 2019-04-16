package main

import "fmt"

func findDuplicate(nums []int) int {
	x, y := nums[0], nums[nums[0]]
	for x != y {
		x, y = nums[x], nums[nums[y]]
	}
	x = 0
	for x != y {
		x, y = nums[x], nums[y]
	}
	return x
}
func main() {
	fmt.Println(findDuplicate([]int{1, 2, 3, 4, 3}))
}
