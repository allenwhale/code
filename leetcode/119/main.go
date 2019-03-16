package main

import "fmt"

func getRow(rowIndex int) []int {
	ans := []int{1}
	for i := 1; i <= rowIndex; i++ {
		ans = append(ans, (ans[len(ans)-1]*(rowIndex-(i-1)))/i)
	}
	return ans
}
func main() {
	for i := 0; i < 5; i++ {
		fmt.Println(i, getRow(i))
	}

}
