package main

import (
	"fmt"
	"math"
)

type DisjointSet struct {
	p, g []int
	N    int
}

func (this *DisjointSet) Init(N int) {
	this.N, this.p, this.g = N, make([]int, N), make([]int, N)
	for i := range this.p {
		this.p[i] = i
		this.g[i] = 1
	}
}
func (this *DisjointSet) Find(x int) int {
	if x == this.p[x] {
		return x
	}
	this.p[x] = this.Find(this.p[x])
	return this.p[x]
}
func (this *DisjointSet) Union(a, b int) {
	pa, pb := this.Find(a), this.Find(b)
	if pa == pb {
		return
	}
	this.g[pb], this.g[pa] = this.g[pb]+this.g[pa], 0
	this.p[pa] = pb
}

func makePrime(mx int) []int {
	primes, notPrime := []int{2}, make([]bool, mx+1)
	notPrime[0], notPrime[1] = true, true
	for i := 3; i <= mx; i = i + 2 {
		if !notPrime[i] {
			primes = append(primes, i)
			for _, p := range primes {
				if p*i <= mx {
					notPrime[p*i] = true
				} else {
					break
				}
			}
		}
	}
	return primes
}

func largestComponentSize(A []int) int {
	djs := &DisjointSet{}
	djs.Init(len(A))
	mxA := math.MinInt32
	for _, x := range A {
		if mxA < x {
			mxA = x
		}
	}
	primes := makePrime(mxA)
	mp := make(map[int][]int, len(primes))

	for i, a := range A {
		aa := a
		for _, p := range primes {
			if p*p > a {
				break
			}
			if aa%p == 0 {
				aa = aa / p
				mp[p] = append(mp[p], i)
			}
			for aa%p == 0 {
				aa = aa / p
			}
		}
		if aa != 1 {
			mp[aa] = append(mp[aa], i)
		}
	}
	for _, l := range mp {
		if len(l) <= 1 {
			continue
		}
		for _, i := range l {
			djs.Union(i, l[0])
		}
	}
	mxg := 0
	for _, g := range djs.g {
		if mxg < g {
			mxg = g
		}
	}
	return mxg
}
func main() {
	fmt.Println(largestComponentSize([]int{4, 6, 15, 35}))
}
