package main

import "fmt"

func intervalIntersection(A [][]int, B [][]int) [][]int {
	i, j, ans := 0, 0, [][]int{}
	for i < len(A) && j < len(B) {
		l, r := 0, 0
		if A[i][0] < B[j][0] {
			l = B[j][0]
		} else {
			l = A[i][0]
		}
		if A[i][1] < B[j][1] {
			r = A[i][1]
		} else {
			r = B[j][1]
		}
		if l <= r {
			ans = append(ans, []int{l, r})
		}
		if A[i][1] < B[j][1] {
			i++
		} else {
			j++
		}
	}
	return ans
}
func main() {
	fmt.Println(intervalIntersection([][]int{[]int{0, 2}, []int{5, 10}}, [][]int{[]int{1, 5}, []int{8, 12}}))
}
