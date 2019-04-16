package main

import (
	"fmt"
)

func repeatedSubstringPattern(s string) bool {
	f := make([]int, len(s))
	f[0] = -1
	for i, j := 1, -1; i < len(s); i++ {
		for j >= 0 && s[j+1] != s[i] {
			j = f[j]
		}
		if s[j+1] == s[i] {
			j++
		}
		f[i] = j
	}
	return f[len(s)-1] != -1 && len(s)%(len(s)-f[len(s)-1]-1) == 0

}
func main() {
	fmt.Println(repeatedSubstringPattern("abcabcabc"))
}
