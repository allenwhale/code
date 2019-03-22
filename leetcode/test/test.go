package test

import (
	"gopkg.in/karalabe/cookiejar.v1/collections/deque"
)

func Append(arr *[]int, v int) {
	*arr = append(*arr, v)
}
func Prepend(arr *[]int, v int) {
	*arr = append([]int{v}, (*arr)...)
}
func Dq(arr *deque.Deque, v int) {
	arr.PushRight(v)
}
