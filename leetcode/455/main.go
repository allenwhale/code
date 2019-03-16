package main

import "sort"

func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	i, j, ans := len(g)-1, len(s)-1, 0
	for i >= 0 && j >= 0 {
		if s[j] >= g[i] {
			ans, i, j = ans+1, i-1, j-1
		} else {
			i = i - 1
		}
	}
	return ans
}
func main() {

}
