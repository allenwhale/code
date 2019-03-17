package main

import "fmt"

func upper(x byte) byte {
	if 'a' <= x && x <= 'z' {
		return 'A' + x - 'a'
	}
	return x
}

func licenseKeyFormatting(S string, K int) string {
	bs := make([]byte, 0, len(S))
	for _, v := range S {
		if v != '-' {
			bs = append(bs, upper(byte(v)))
		}
	}
	l := len(bs)
	ans := make([]byte, 0, len(S))
	if l%K != 0 {
		ans = append(ans, bs[:l%K]...)
		ans = append(ans, '-')
		bs = bs[l%K:]
	}
	for i := 0; i < l/K; i++ {
		ans = append(ans, bs[:K]...)
		ans = append(ans, '-')
		bs = bs[K:]
	}
	if len(ans) > 0 {
		ans = ans[:len(ans)-1]
	}

	return string(ans)
}
func main() {
	fmt.Println(licenseKeyFormatting("5F3Z-2e-9-w", 4))
}
