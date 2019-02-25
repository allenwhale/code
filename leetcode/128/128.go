package main

import "fmt"

func longestConsecutive(nums []int) int {
	h, t := map[int]int{}, map[int]int{}
	vis := map[int]bool{}
	for _, x := range nums {
		if vis[x] {
			continue
		}
		vis[x] = true
		hv, hok := h[x+1]
		tv, tok := t[x-1]
		if hok && tok {
			delete(h, x+1)
			delete(t, x-1)
			h[x-1-tv+1] = hv + tv + 1
			t[x+1+hv-1] = hv + tv + 1
		} else if hok {
			delete(h, x+1)
			h[x] = hv + 1
			t[x+1+hv-1] = hv + 1
		} else if tok {
			delete(t, x-1)
			t[x] = tv + 1
			h[x-1-tv+1] = tv + 1
		} else {
			h[x] = 1
			t[x] = 1
		}
	}
	ans := 0
	for _, v := range h {
		if v > ans {
			ans = v
		}
	}
	return ans
}
func main() {
	fmt.Println(longestConsecutive([]int{-7, -1, 3, -9, -4, 7, -3, 2, 4, 9, 4, -9, 8, -7, 5, -1, -7}))
}
