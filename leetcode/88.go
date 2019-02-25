package main

import "fmt"

func merge(nums1 []int, n int, nums2 []int, m int) {
	i, j, k := n-1, m-1, m+n-1
	for i >= 0 && j >= 0 {
		if nums1[i] > nums2[j] {
			nums1[k], i, k = nums1[i], i-1, k-1
		} else {
			nums1[k], j, k = nums2[j], j-1, k-1
		}
	}
	for i >= 0 {
		nums1[k], i, k = nums1[i], i-1, k-1
	}
	for j >= 0 {
		nums1[k], j, k = nums2[j], j-1, k-1
	}
}
func main() {
	a, b := []int{1, 2, 3, 0, 0, 0}, []int{2, 5, 6}
	merge(a, 3, b, 3)
	fmt.Println(a)
}
