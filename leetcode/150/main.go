package main

import (
	"fmt"
	"strconv"
)

func evalRPN(tokens []string) int {
	stk := make([]int, 0)
	for _, x := range tokens {
		if len(x) == 1 && (x[0] == '+' || x[0] == '-' || x[0] == '/' || x[0] == '*') {
			len := len(stk)
			a, b := stk[len-2], stk[len-1]
			stk = stk[:len-2]
			switch x[0] {
			case '+':
				stk = append(stk, a+b)
			case '-':
				stk = append(stk, a-b)
			case '/':
				stk = append(stk, a/b)
			case '*':
				stk = append(stk, a*b)
			}
		} else {
			v, _ := strconv.Atoi(x)
			stk = append(stk, v)
		}
	}
	return stk[0]
}

func main() {
	fmt.Println(evalRPN([]string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}))
}
