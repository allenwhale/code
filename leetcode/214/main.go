package main

import "fmt"

/*
 * @lc app=leetcode id=214 lang=golang
 *
 * [214] Shortest Palindrome
 */
func rev(s string) string {
	res := []rune(s)
	l := len(res)
	for i := 0; i*2 < l; i++ {
		res[i], res[l-i-1] = res[l-i-1], res[i]
	}
	return string(res)
}
func shortestPalindrome(s string) string {
	l1 := len(s)
	if l1 == 0 {
		return ""
	}
	l2 := 2*l1 + 1
	ss := make([]byte, l2)
	z := make([]int, l2)
	for i := 0; i < l2; i++ {
		if (i & 1) != 0 {
			ss[i] = s[i/2]
		} else {
			ss[i] = '!'
		}
	}
	z[0] = 1
	l, r := 0, 0
	for i := 1; i < l2; i++ {
		if i > r {
			l, r = i, i
			for l > 0 && r < l2-1 && ss[l-1] == ss[r+1] {
				l, r = l-1, r+1
			}
			z[i] = r - l + 1
		} else {
			z[i] = z[((l+r)&(^1))-i]
			nr := i + z[i]/2
			if nr == r {
				l = i*2 - r
				for l > 0 && r < l2-1 && ss[l-1] == ss[r+1] {
					l, r = l-1, r+1
				}
				z[i] = r - l + 1
			} else if nr > r {
				z[i] = (r-i)*2 + 1
			}

		}
	}
	for i := l2 - 1; i >= 0; i-- {
		if (z[i]-1)/2 == i {
			return rev(s[z[i]/2:]) + s
		}
	}
	return ""
}

func main() {
	fmt.Println(shortestPalindrome("abbacd"))
	fmt.Println(shortestPalindrome("aacecaaa"))
	fmt.Println(shortestPalindrome("abcd"))
}
