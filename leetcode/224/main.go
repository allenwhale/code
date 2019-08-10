package main

import "fmt"

func removeSpace(s string, i *int) {
	for *i < len(s) && s[*i] == ' ' {
		*i++
	}
}
func getInt(s string, i *int) int {
	res := 0
	for *i < len(s) && isDigit(s[*i]) {
		res = res*10 + (int(s[*i]) - int('0'))
		*i++
	}
	return res
}
func isDigit(c byte) bool {
	return '0' <= c && c <= '9'
}
func add(a, b, f int) int {
	if f == 1 {
		return a + b
	}
	return a - b
}
func calc(s string, i *int) int {
	res, f := 0, 1
	for {
		if removeSpace(s, i); *i < len(s) {
			if s[*i] == '(' {
				*i++
				res = add(res, calc(s, i), f)
			} else if s[*i] == ')' {
				*i++
				break
			} else if s[*i] == '-' {
				f, *i = -1, *i+1
			} else if s[*i] == '+' {
				f, *i = 1, *i+1
			} else if isDigit(s[*i]) {
				res = add(res, getInt(s, i), f)
			}
		} else {
			break
		}
	}
	return res
}
func calculate(s string) int {
	i := 0
	return calc(s, &i)
}
func main() {
	fmt.Println(calculate("1 + 1"))
	fmt.Println(calculate(" 2-1 + 2 "))
	fmt.Println(calculate("(1+(4+5+2)-3)+(6+8)"))
}
