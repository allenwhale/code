package main

import "fmt"

func bestRotation(A []int) int {
	N, cnt := len(A), [20010]int{}
	for i, v := range A {
		r, l := (i-v+N+1)%N, (i-(N-1)+N)%N
		cnt[l]++
		cnt[r]--
		if l >= r {
			cnt[0]++
		}
	}
	cur, ans, idx := 0, 0, -1
	for i := 0; i < N; i++ {
		cur += cnt[i]
		if cur > ans {
			ans = cur
			idx = i
		}
	}
	return idx
}
func main() {
	fmt.Println(bestRotation([]int{2, 3, 1, 4, 0}))
	fmt.Println(bestRotation([]int{1, 3, 0, 2, 4}))
}
