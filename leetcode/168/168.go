package main

import "fmt"

func convertToTitle(n int) string {
	n = n - 1
	ans := string(byte('A') + byte(n%26))
	n = n / 26
	for n != 0 {
		n = n - 1
		ans = string(byte('A')+byte(n%26)) + ans
		n = n / 26
	}
	return ans
}
func main() {
	fmt.Println(convertToTitle(1))
	fmt.Println(convertToTitle(27))
	fmt.Println(convertToTitle(701))
}
