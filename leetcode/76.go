package main

import (
	_ "fmt"
	"github.com/kr/pretty"
)

func minWindow(s string, t string) string {
	cnt, fail := [128]int{}, 0
	for _, v := range t {
		if cnt[v] == 0 {
			fail++
		}
		cnt[v]++
	}
	ansStart, ansLen := -1, len(s)+1
	for l, r := 0, 0; r < len(s); r++ {
		cnt[s[r]]--
		if cnt[s[r]] == 0 {
			fail--
		}
		for ; fail == 0; l++ {
			if r-l+1 < ansLen {
				ansStart, ansLen = l, r-l+1
			}
			cnt[s[l]]++
			if cnt[s[l]] == 1 {
				fail++
			}
		}
	}
	if ansStart != -1 {
		return s[ansStart : ansStart+ansLen]
	}
	return ""
}
func main() {
	pretty.Println(minWindow("ADOBECODEBANC", "ABC"))
	pretty.Println(minWindow("1", "1"))
}
