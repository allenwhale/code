package main

import (
	"fmt"
)

func removeKdigits(num string, k int) string {
	if len(num) <= k {
		return "0"
	}
	ans := make([]byte, 0)
	for _, x := range num {
		c := byte(x)
		for k > 0 && len(ans) > 0 && c < ans[len(ans)-1] {
			ans, k = ans[:len(ans)-1], k-1
		}
		ans = append(ans, c)
	}
	ans = ans[:len(ans)-k]
	for len(ans) > 0 && ans[0] == '0' {
		ans = ans[1:]
	}
	if len(ans) == 0 {
		ans = append(ans, '0')
	}
	return string(ans)
}
func main() {
	fmt.Println(removeKdigits("1432219", 3))
	fmt.Println(removeKdigits("10200", 1))
	fmt.Println(removeKdigits("10", 2))
}
