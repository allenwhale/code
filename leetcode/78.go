package main

import (
	"github.com/kr/pretty"
)

func subsets(nums []int) [][]int {
	ans, n := [][]int{}, uint(len(nums))
	for i := 0; i < (1 << n); i++ {
		buf := []int{}
		for j := uint(0); j < n; j++ {
			if (i & (1 << j)) != 0 {
				buf = append(buf, nums[j])
			}
		}
		ans = append(ans, buf)
	}
	return ans
}
func main() {
	pretty.Println(subsets([]int{1, 2, 3}))
}
