package main

import (
	"fmt"
	"math"
	"strconv"
)

func check(n int64, p int) int64 {
	if p == 1 {
		return n - 1
	}
	b := int64(math.Pow(float64(n), 1./float64(p)))
	if b == 1 {
		return -1
	}
	x, s := int64(1), int64(1)
	for i := 0; i < p; i++ {
		x = x * b
		s = s + x
	}
	if n == s {
		return b
	} else {
		return -1
	}
}

func smallestGoodBase(n string) string {
	nn, _ := strconv.ParseInt(n, 10, 64)
	for i := 64; i >= 0; i-- {
		if b := check(nn, i); b != -1 {
			return strconv.FormatInt(b, 10)
		}
	}
	return "-1"
}
func main() {
	fmt.Println(smallestGoodBase("13"))
	fmt.Println(smallestGoodBase("4681"))
	fmt.Println(smallestGoodBase("1000000000000000000"))
}
