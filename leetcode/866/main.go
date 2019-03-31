package main

import (
	"fmt"
	"math"
	"strconv"
)

func powMod(x, n, m int64) int64 {
	res := int64(1)
	x = x % m
	for n != 0 {
		if n&1 == 1 {
			res = (res * x) % m
		}
		x, n = (x*x)%m, n>>1

	}
	return res
}

func primeTest(a, n, u int64, t int) bool {
	x := powMod(a, u, n)
	for i := 0; i < t; i++ {
		nx := (x * x) % n
		if nx == 1 && x != 1 && x != n-1 {
			return true
		}
		x = nx
	}
	return x != 1
}

func millerRabin(n int64) bool {
	if n == 2 || n == 3 {
		return true
	}
	if n < 2 || n&1 == 0 {
		return false
	}
	u, t := n-1, 0
	for u&1 == 0 {
		u, t = u>>1, t+1
	}
	for _, x := range []int64{2, 7, 61} {
		if x%n != 0 && primeTest(x%n, n, u, t) {
			return false
		}
	}
	return true
}

func format(sh, l int) int {
	res := sh
	if l&1 == 1 {
		sh = sh / 10
	}
	for i := 0; i < l/2; i++ {
		res, sh = res*10+sh%10, sh/10
	}
	return res
}

func primePalindrome(N int) int {
	if N <= 2 {
		return 2
	}
	s := strconv.FormatInt(int64(N), 10)
	l := len(s)
	m := (l + 1) / 2
	sh, _ := strconv.ParseInt(s[:m], 10, 64)
	st, ed := sh, powMod(int64(10), int64(m), math.MaxInt64)-1
	for i := st; i <= ed; i++ {
		ss := format(int(i), l)
		// fmt.Println(1, i, ss)
		if ss >= N && millerRabin(int64(ss)) {
			return ss
		}
	}
	for {

		l = l + 1
		m = (l + 1) / 2
		st, ed = powMod(int64(10), int64(m-1), math.MaxInt64), powMod(int64(10), int64(m), math.MaxInt64)-1
		for i := st; i <= ed; i++ {
			ss := format(int(i), l)
			// fmt.Println(2, i, ss)
			if millerRabin(int64(ss)) {
				return ss
			}
		}
	}
}
func main() {
	fmt.Println(primePalindrome(930))
	// fmt.Println(primePalindrome(8))
	// fmt.Println(primePalindrome(11))
	// fmt.Println(primePalindrome(13))
}
