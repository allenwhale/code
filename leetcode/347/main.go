package main

import "fmt"

func topKFrequent(nums []int, k int) []int {
	cnt := make(map[int]int, len(nums))
	for _, x := range nums {
		cnt[x]++
	}
	cnt2 := make([]map[int]bool, len(nums))
	for k, v := range cnt {
		if cnt2[v-1] == nil {
			cnt2[v-1] = make(map[int]bool, 1)
		}
		cnt2[v-1][k] = true
	}
	ans := make([]int, 0, k)
	for i := len(nums) - 1; i >= 0 && len(ans) < k; i-- {
		if len(cnt2[i]) > 0 {
			for x := range cnt2[i] {
				ans = append(ans, x)
				if len(ans) >= k {
					break
				}
			}
		}
	}
	return ans
}
func main() {
	fmt.Println(topKFrequent([]int{4, 1, -1, 2, -1, 2, 3}, 2))
}
