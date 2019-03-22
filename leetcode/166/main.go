package main

import (
	"fmt"
	"strconv"
)

func fractionToDecimal(numerator int, denominator int) string {
	sgn := 0
	if (numerator < 0) != (denominator < 0) {
		sgn = 1
	}
	if numerator < 0 {
		numerator = -numerator
	}
	if denominator < 0 {
		denominator = -denominator
	}
	a := numerator / denominator
	numerator = numerator % denominator
	mp := make(map[int]int)
	f := make([]int, 0)
	for i := 0; numerator != 0; i++ {
		if _, ok := mp[numerator]; ok {
			break
		}
		mp[numerator] = i
		f = append(f, numerator*10/denominator)
		numerator = (numerator * 10) % denominator
	}
	ans := []byte(strconv.FormatInt(int64(a), 10))
	if numerator == 0 {
		if len(f) != 0 {
			ans = append(ans, '.')
			for _, v := range f {
				ans = append(ans, byte(int('0')+v))
			}
		}
	} else {
		ans = append(ans, '.')
		for i := 0; i < mp[numerator]; i++ {
			ans = append(ans, byte(int('0')+f[i]))
		}
		ans = append(ans, '(')
		for i := mp[numerator]; i < len(f); i++ {
			ans = append(ans, byte(int('0')+f[i]))
		}
		ans = append(ans, ')')
	}
	if sgn == 1 && (a != 0 || len(f) != 0) {
		return "-" + string(ans)
	}
	return string(ans)
}
func main() {
	fmt.Println(fractionToDecimal(-1, 3))
	fmt.Println(fractionToDecimal(2, 3))
	fmt.Println(fractionToDecimal(1, 7))
}
