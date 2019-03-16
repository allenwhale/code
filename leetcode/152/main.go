package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func maxProduct(nums []int) int {
	res, mx, mn := nums[0], nums[0], nums[0]
	for _, x := range nums[1:] {
		if x >= 0 {
			mx, mn = max(x, mx*x), min(x, mn*x)
		} else {
			mx, mn = max(x, mn*x), min(x, mx*x)
		}
		res = max(res, mx)
	}
	return res
}
func main() {
	// fmt.Println(maxProduct([]int{2, 3, -2, 4}))
	// fmt.Println(maxProduct([]int{-2, 0, -1}))
	fmt.Println(maxProduct([]int{-4, -3, -2}))

}
