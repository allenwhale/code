package main

import "fmt"

func candy(ratings []int) int {
	ans, up, down, peak := 1, 0, 0, 0
	for i := 1; i < len(ratings); i++ {
		if ratings[i-1] < ratings[i] {
			up = up + 1
			down, peak, ans = 0, up, ans+up+1
		} else if ratings[i-1] > ratings[i] {
			down = down + 1
			up, ans = 0, ans+down
			if down > peak {
				ans = ans + 1
			}
		} else {
			up, down, peak, ans = 0, 0, 0, ans+1
		}
	}
	return ans
}
func main() {
	fmt.Println(candy([]int{1, 3, 2, 2, 1}))
	// fmt.Println(candy([]int{1, 0, 2}))
	// fmt.Println(candy([]int{1, 2, 2}))
	// fmt.Println(candy([]int{1, 1, 1}))
}
