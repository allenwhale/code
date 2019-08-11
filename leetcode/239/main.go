package main

import "fmt"

func maxSlidingWindow(nums []int, k int) []int {
	res, s, si, i := make([]int, 0, len(nums)), make([]int, 0, len(nums)), make([]int, 0, len(nums)-k), 0
	for ; i < k-1; i++ {
		for len(s) > 0 && s[len(s)-1] <= nums[i] {
			s, si = s[:len(s)-1], si[:len(si)-1]
		}
		s, si = append(s, nums[i]), append(si, i)
	}
	for ; i < len(nums); i++ {
		for len(s) > 0 && i-si[0] >= k {
			s, si = s[1:], si[1:]
		}
		for len(s) > 0 && s[len(s)-1] <= nums[i] {
			s, si = s[:len(s)-1], si[:len(si)-1]
		}
		s, si, res = append(s, nums[i]), append(si, i), append(res, s[0])
	}
	return res
}
func main() {
	fmt.Println(maxSlidingWindow([]int{1, 3, 1, 2, 0, 5}, 3))
}
