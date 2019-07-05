package main

import "fmt"

func distributeCandies(candies []int) int {
	vis := make(map[int]bool)
	for _, v := range candies {
		vis[v] = true
	}
	if len(vis) >= len(candies)/2 {
		return len(candies) / 2
	} else {
		return len(vis)
	}
}
func main() {
	fmt.Println(distributeCandies([]int{1, 1, 2, 2, 3, 3}))
	fmt.Println(distributeCandies([]int{1, 1, 2, 3}))
}
