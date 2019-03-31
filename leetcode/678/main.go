package main

import "fmt"

func checkValidString(s string) bool {
	l, h := 0, 0
	for _, c := range s {
		switch c {
		case '(':
			l, h = l+1, h+1
		case ')':
			l, h = l-1, h-1
		case '*':
			l, h = l-1, h+1
		}
		if h < 0 {
			return false
		}
		if l < 0 {
			l = 0
		}
	}
	return l <= 0 && 0 <= h
}
func main() {
	fmt.Println(checkValidString("))((((()*()*(())())(()))((*()(*((*(*()))()(())*()()))*)*()))()()(())()(()))()))))")
}
