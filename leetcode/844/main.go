package main

import "fmt"

func backspaceCompare(S string, T string) bool {
	i, j := len(S)-1, len(T)-1
	for i >= 0 || j >= 0 {
		b := 0
		for i >= 0 {
			if S[i] == '#' {
				b = b + 1
			} else if b > 0 {
				b = b - 1
			} else {
				break
			}
			i = i - 1
		}
		b = 0
		for j >= 0 {
			if T[j] == '#' {
				b = b + 1
			} else if b > 0 {
				b = b - 1
			} else {
				break
			}
			j = j - 1
		}

		if i >= 0 && j >= 0 && S[i] != T[j] {
			return false
		}
		if (i < 0) != (j < 0) {
			return false
		}
		i, j = i-1, j-1
	}
	// fmt.Println(i, j)
	return true
}
func main() {
	fmt.Println(backspaceCompare("ab#c", "ad#c"))
	fmt.Println(backspaceCompare("ab##", "c#d#"))
	fmt.Println(backspaceCompare("a##c", "#a#c"))
	fmt.Println(backspaceCompare(
		"bbbextm",
		"bbb#extm"))
}
