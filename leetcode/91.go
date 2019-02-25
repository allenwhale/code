package main

import "fmt"
import "strconv"

func numDecodings(s string) int {
	if len(s) == 0 || s[0] == '0' {
		return 0
	}
	a, b := 1, 1
	for i := 1; i < len(s); i += 1 {
		if x, _ := strconv.Atoi(s[i-1 : i+1]); s[i-1] != '0' && 0 < x && x <= 26 {
			if s[i] == '0' {
				a, b = b, a
			} else {
				a, b = b, a+b
			}
		} else {
			if s[i] == '0' {
				a, b = b, 0
			} else {
				a, b = b, b
			}
		}
	}
	return b
}
func main() {
	fmt.Println(numDecodings("101"))
	fmt.Println(numDecodings("12"))
	fmt.Println(numDecodings("226"))
}
