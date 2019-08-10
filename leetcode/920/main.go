package main

import "fmt"

const (
	MOD = int64(1e9 + 7)
)

func pow(a, n int64) int64 {
	res, now := int64(1), a
	for n != 0 {
		if n&1 == 1 {
			res = (res * now) % MOD
		}
		now = (now * now) % MOD
		n >>= 1
	}
	return res
}
func inv(x int64) int64 {
	return pow(x, MOD-int64(2))
}
func numMusicPlaylists(N int, L int, K int) int {
	n, l, k := int64(N), int64(L), int64(K)
	p, f, c := int64(1), int64(-1), int64(1)
	for i := n; i > n-k; i-- {
		p = (p * i) % MOD
	}
	ans := (p * pow(n-k, l-k)) % MOD
	for i := int64(1); i < n-k; i++ {
		p = (((p * (n - k - i + 1)) % MOD) * inv(n-i+1)) % MOD
		c = (((c * (n - i + 1)) % MOD) * inv(i)) % MOD
		ans = (ans + f*((p*c)%MOD)*pow(n-k-i, l-k)) % MOD
		f = -f
	}
	return int((ans + MOD) % MOD)
}

func main() {
	fmt.Println(numMusicPlaylists(25, 28, 5))
	fmt.Println(numMusicPlaylists(3, 3, 1))
	fmt.Println(numMusicPlaylists(2, 3, 0))
	fmt.Println(numMusicPlaylists(2, 3, 1))
}
