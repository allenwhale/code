package main

import "sort"

func hash(s []int) int64 {
	res := int64(0)
	for _, x := range s {
		res = (res*int64(131) + int64(x) + int64(91827364)) % int64(1000000007)
	}
	return res
}
func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	ans := [][]int{[]int{}}
	set := make(map[int64]int)
	for b := 1; b < 1<<uint(len(nums)); b += 1 {
		tmp := []int(nil)
		for i := 0; i < len(nums); i += 1 {
			if b&(1<<uint(i)) != 0 {
				tmp = append(tmp, nums[i])
			}
		}
		h := hash(tmp)
		if _, ok := set[h]; !ok {
			set[h] = 1
			ans = append(ans, tmp)
		}
	}
	return ans
}
func main() {}
