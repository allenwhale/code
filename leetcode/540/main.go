package main

import "fmt"

func singleNonDuplicate(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}
	l, r := 0, len(nums)-1
	for l < r {
		mid := (l + r) / 2
		if nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1] {
			return nums[mid]
		} else if nums[mid] != nums[mid-1] {
			if (mid-l)%2 == 1 {
				r = mid - 1
			} else {
				l = mid + 2
			}
		} else {
			if (mid-l+1)%2 == 1 {
				r = mid - 2
			} else {
				l = mid + 1
			}
		}
	}
	return nums[l]
}
func main() {
	fmt.Println(singleNonDuplicate([]int{1, 1, 2, 3, 3, 4, 4, 8, 8}))
	fmt.Println(singleNonDuplicate([]int{3, 3, 7, 7, 10, 11, 11}))
}
