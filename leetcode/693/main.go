package main

import "fmt"

func hasAlternatingBits(n int) bool {
	if n <= 2 {
		return true
	}
	b := n & 1
	n = n >> 1
	for n != 0 {
		if b == n&1 {
			return false
		}
		b, n = n&1, n>>1
	}
	return true
}
func main() {
	for i := 0; i <= 10; i++ {
		fmt.Println(i, hasAlternatingBits(i))
	}

}
