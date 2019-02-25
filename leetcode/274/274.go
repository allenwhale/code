package main

import "fmt"

func hIndex(citations []int) int {
	cnt := make([]int, len(citations)+1)
	for _, x := range citations {
		if x > len(citations) {
			x = len(citations)
		}
		cnt[x]++
	}
	for i := len(cnt) - 2; i >= 0; i-- {
		cnt[i] = cnt[i] + cnt[i+1]
	}
	for i := len(cnt) - 1; i >= 0; i-- {
		if cnt[i] >= i {
			return i
		}
	}
	return -1
}
func main() {
	fmt.Println(hIndex([]int{3, 0, 6, 1, 5}))
}
