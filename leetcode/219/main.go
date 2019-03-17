package main

import "fmt"

func containsNearbyDuplicate(nums []int, k int) bool {
	mp := make(map[int]int)
	for i := 0; i < k && i < len(nums); i++ {
		mp[nums[i]]++
		if mp[nums[i]] > 1 {
			return true
		}
	}
	for i := k; i < len(nums); i++ {
		mp[nums[i]]++
		if mp[nums[i]] > 1 {
			return true
		}
		mp[nums[i-k]]--
	}
	return false
}
func main() {
	fmt.Println(containsNearbyDuplicate([]int{1, 0, 1, 1}, 1))
}
