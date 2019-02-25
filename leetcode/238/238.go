package main

import "fmt"

func productExceptSelf(nums []int) []int {
	res := make([]int, len(nums))
	res[0] = 1
	for i := 1; i < len(nums); i++ {
		res[i] = res[i-1] * nums[i-1]
	}
	tmp := 1
	for i := len(nums) - 2; i >= 0; i-- {
		tmp = tmp * nums[i+1]
		res[i] = res[i] * tmp
	}
	return res
}
func main() {
	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))
}
