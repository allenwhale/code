package main

import "strconv"

func calPoints(ops []string) int {
	stk, ans := make([]int, 0), 0
	for _, x := range ops {
		switch x {
		case "C":
			stk, ans = stk[:len(stk)-1], ans-stk[len(stk)-1]
		case "D":
			v := stk[len(stk)-1] * 2
			stk, ans = append(stk, v), ans+v
		case "+":
			v := stk[len(stk)-1] + stk[len(stk)-2]
			stk, ans = append(stk, v), ans+v
		default:
			v, _ := strconv.Atoi(x)
			stk, ans = append(stk, v), ans+v
		}
	}
	return ans
}
func main() {

}
