package main

import (
	"fmt"
	"math"
)

func maximumGap(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	min, max := nums[0], nums[0]
	for _, v := range nums {
		if v < min {
			min = v
		}
		if v > max {
			max = v
		}
	}
	bSize := (max - min + len(nums)) / len(nums)
	bNum := (max - min + bSize) / bSize
	valueToIndex := func(v int) int {
		return (v - min) / bSize
	}
	bMin := make([]int, bNum)
	bMax := make([]int, bNum)
	updateBucket := func(v int) {
		bID := valueToIndex(v)
		if v < bMin[bID] {
			bMin[bID] = v
		}
		if v > bMax[bID] {
			bMax[bID] = v
		}
	}
	for i := 0; i < bNum; i++ {
		bMin[i], bMax[i] = math.MaxInt32, math.MinInt32
	}
	for _, v := range nums {
		updateBucket(v)
	}
	ans, lastMax := 0, math.MinInt32
	for i := 0; i < bNum; i++ {
		if bMin[i] != math.MaxInt32 {
			gap := bMax[i] - bMin[i]
			if gap > ans {
				ans = gap
			}
			if lastMax != math.MinInt32 {
				gap = bMin[i] - lastMax
				if gap > ans {
					ans = gap
				}
			}
			lastMax = bMax[i]
		}
	}
	return ans
}
func main() {
	fmt.Println(maximumGap([]int{1, 3, 100}))
	fmt.Println(maximumGap([]int{3, 6, 9, 1}))
	fmt.Println(maximumGap([]int{10}))
}
