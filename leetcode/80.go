package main

import (
	"github.com/kr/pretty"
)

func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	dst, cnt, last := 0, 0, nums[0]
	for _, v := range nums {
		if v == last {
			cnt++
			if cnt <= 2 {
				nums[dst], dst, last = v, dst+1, v
			}
		} else {
			nums[dst], dst, last, cnt = v, dst+1, v, 1
		}
	}
	return dst
}
func main() {
	nums := []int{0, 0, 1, 1, 1, 1, 2, 2}
	pretty.Println(removeDuplicates(nums), nums)
}
