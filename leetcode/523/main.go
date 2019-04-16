package main

import (
	"fmt"
)

func checkSubarraySum(nums []int, k int) bool {

	if k < 0 {
		k = -k
	}
	m := make(map[int]int)
	m[0] = -1
	sum := 0
	for i, v := range nums {
		sum = (sum + v)
		if k != 0 {
			sum = sum % k
		}
		// pretty.Println(m, i, sum)
		if j, ok := m[sum]; ok && i-j >= 2 {
			return true
		}
		if _, ok := m[sum]; !ok {
			m[sum] = i
		}
	}
	return false
}

func main() {
	fmt.Println(checkSubarraySum([]int{0, 0}, 0))
}
