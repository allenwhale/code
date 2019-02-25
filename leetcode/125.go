package main

import "fmt"

func lower(x byte) byte {
	if 'A' <= x && x <= 'Z' {
		x += 32
	}
	return x
}
func an(x byte) bool {
	return ('a' <= x && x <= 'z') || ('0' <= x && x <= '9')
}
func isPalindrome(s string) bool {
	bs := []byte(s)
	i, j := 0, len(bs)-1
	for i, x := range bs {
		bs[i] = lower(x)
	}
	for i < j {
		if !an(bs[i]) {
			i += 1
			continue
		}
		if !an(bs[j]) {
			j -= 1
			continue
		}
		if bs[i] != bs[j] {
			return false
		} else {
			i, j = i+1, j-1
		}
	}
	return true
}
func main() {
	fmt.Println(isPalindrome("0P"))
}
