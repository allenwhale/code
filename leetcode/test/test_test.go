package test

import (
	"testing"

	"gopkg.in/karalabe/cookiejar.v1/collections/deque"
)

func BenchmarkAppend(b *testing.B) {
	arr := []int{}
	for i := 0; i < b.N; i++ {
		Append(&arr, i)
	}
}

// func BenchmarkPrepend(b *testing.B) {
// 	arr := []int{}
// 	for i := 0; i < b.N; i++ {
// 		Prepend(&arr, i)
// 	}
// }

func BenchmarkDq(b *testing.B) {
	arr := deque.New()
	for i := 0; i < b.N; i++ {
		Dq(arr, i)
	}
}
