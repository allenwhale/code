package main

import (
	"fmt"
	"sort"
)

func lb(x int) int {
	return x & (-x)
}

func update(bit []int, x int) {
	for x < len(bit) {
		bit[x], x = bit[x]+1, x+lb(x)
	}
}

func query(bit []int, x int) int {
	res := 0
	for x > 0 {
		res, x = res+bit[x], x-lb(x)
	}
	return res
}

func countSmaller(nums []int) []int {
	if len(nums) == 0 {
		return nums
	}
	newNums := append([]int(nil), nums...)
	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		newNums[i] = sort.SearchInts(nums, newNums[i]) + 1
	}
	bit := make([]int, sort.SearchInts(nums, nums[len(nums)-1])+1)
	for i := len(newNums) - 1; i >= 0; i-- {
		nums[i] = query(bit, newNums[i]-1)
		update(bit, newNums[i])
	}

	return nums
}
func main() {
	fmt.Println(countSmaller([]int{4, 3, 2, 1}))
}
