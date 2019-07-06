package main

import "fmt"

func asteroidCollision(asteroids []int) []int {
	ans := []int{}
	for _, v := range asteroids {
		if len(ans) == 0 || (ans[len(ans)-1]*v > 0) || (ans[len(ans)-1] < 0 && v > 0) {
			ans = append(ans, v)
		} else {
			for len(ans) > 0 && ans[len(ans)-1] > 0 && ans[len(ans)-1] < -v {
				ans = ans[:len(ans)-1]
			}
			if len(ans) == 0 || ans[len(ans)-1] < 0 {
				ans = append(ans, v)
			} else if ans[len(ans)-1] == -v {
				ans = ans[:len(ans)-1]
			}
		}
	}
	return ans
}
func main() {
	fmt.Println(asteroidCollision([]int{-2, -2, 1, -2}))
	fmt.Println(asteroidCollision([]int{5, 10, -5}))
	fmt.Println(asteroidCollision([]int{8, -8}))
	fmt.Println(asteroidCollision([]int{10, 2, -5}))
	fmt.Println(asteroidCollision([]int{-2, -1, 1, 2}))
}
