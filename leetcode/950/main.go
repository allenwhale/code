package main

import (
	"fmt"
	"sort"
)

func deckRevealedIncreasing(deck []int) []int {
	sort.Ints(deck)
	p := make([]int, len(deck))
	ans := make([]int, len(deck))
	for i := 0; i < len(deck); i++ {
		p[i] = i
	}
	for i := 0; i < len(deck); i++ {
		ans[p[0]] = deck[i]
		p = p[1:]
		if len(p) == 0 {
			break
		}
		p = append(p[1:], p[0])
	}
	return ans
}
func main() {
	fmt.Println(deckRevealedIncreasing([]int{17, 13, 11, 2, 3, 5, 7}))
}
