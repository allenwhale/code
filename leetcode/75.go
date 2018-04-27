package main

import (
	_ "github.com/kr/pretty"
)

func sortColors(nums []int) {
	a, b, c := 0, 0, 0
	for i := 0; i < len(nums); i++ {
		if nums[i] == 0 {
			nums[c], c = 2, c+1
			nums[b], b = 1, b+1
			nums[a], a = 0, a+1
		} else if nums[i] == 1 {
			nums[c], c = 2, c+1
			nums[b], b = 1, b+1
		} else {
			nums[c], c = 2, c+1
		}
	}
}

func main() {
	sortColors([]int{2, 1, 1, 0})
}
