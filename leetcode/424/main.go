package main

import "fmt"

func max(s [26]int) int {
	res := 0
	for _, v := range s {
		if res < v {
			res = v
		}
	}
	return res
}
func characterReplacement(s string, k int) int {
	ans, cnt := 0, [26]int{}
	l, r := 0, 0
	for r < len(s) {
		cnt[s[r]-'A']++
		r++
		for r-l-max(cnt) > k {
			cnt[s[l]-'A']--
			l++
		}
		if ans < r-l {
			ans = r - l
		}
	}
	return ans
}
func main() {
	fmt.Println(characterReplacement("ABAB", 2))
	fmt.Println(characterReplacement("AABABBA", 1))
}
