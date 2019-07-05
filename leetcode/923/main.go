package main

import "fmt"

const (
	Mod = int64(1000000007)
)

func threeSumMulti(A []int, target int) int {
	cnt := [101]int64{}
	cnt2 := [301]int64{}
	for _, v := range A {
		cnt[v]++
	}
	ans := int64(0)
	t := 100
	if target < 100 {
		t = target
	}
	for i := 0; i <= t; i++ {
		ans = (ans + cnt2[target-i]*cnt[i]) % Mod
		if target >= i+i && target-i-i < i {
			ans = (ans + cnt[target-i-i]*((cnt[i]*(cnt[i]-1))/2)) % Mod
		}
		if target == i+i+i {
			ans = (ans + ((cnt[i] * (cnt[i] - 1) * (cnt[i] - 2)) / 6)) % Mod
		}
		for j := 0; j < i; j++ {
			cnt2[i+j] += cnt[i] * cnt[j]
		}
		cnt2[i+i] += int64((cnt[i] * (cnt[i] - 1)) / 2)

	}
	return int(ans)
}
func main() {
	fmt.Println(threeSumMulti([]int{0, 2, 0, 0}, 2))
	// fmt.Println(threeSumMulti([]int{1, 1, 2, 2, 3, 3, 4, 4, 5, 5}, 8))
	// fmt.Println(threeSumMulti([]int{1, 1, 2, 2, 2, 2}, 5))
}
