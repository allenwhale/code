package main

import "fmt"

func findKthLargest(nums []int, k int) int {
	fmt.Println("n", k, nums)
	piv := 0
	i, j := 0, len(nums)-1
	for i <= j {
		if nums[i] >= nums[piv] {
			nums[i], nums[piv], i, piv = nums[piv], nums[i], i+1, i
		} else {
			nums[i], nums[j], j = nums[j], nums[i], j-1
		}
	}
	fmt.Println("i", piv, nums)
	if k == piv+1 {
		return nums[piv]
	} else if k < piv+1 {
		return findKthLargest(nums[:piv+1], k)
	} else {
		return findKthLargest(nums[piv+1:], k-piv-1)
	}
}
func main() {
	fmt.Println(findKthLargest([]int{3, 2, 1, 5, 6, 4}, 2))
}
