package main

import (
	"fmt"
	"strconv"
)

func nextInt(E []byte) (int, []byte) {
	sgn, num := 1, 0
	if E[0] == '+' {
		E = E[1:]
	} else if E[0] == '-' {
		E, sgn = E[1:], -1
	}
	for len(E) > 0 && '0' <= E[0] && E[0] <= '9' {
		E, num = E[1:], num*10+int(E[0]-'0')
	}
	return num * sgn, E
}

type Frac struct {
	a, b int
}

func gcd(a, b int) int {
	for {
		a = a % b
		if a == 0 {
			break
		}
		b = b % a
		if b == 0 {
			break
		}
	}
	return a + b
}
func lcm(a, b int) int {
	g := gcd(a, b)
	return a / g * b
}

func (this *Frac) Update() *Frac {
	sgn := (this.a < 0) != (this.b < 0)
	if this.a < 0 {
		this.a = -this.a
	}
	if this.b < 0 {
		this.b = -this.b
	}
	g := gcd(this.a, this.b)
	this.a, this.b = this.a/g, this.b/g
	if sgn {
		this.a = -this.a
	}
	return this
}
func (x *Frac) Add(y *Frac) *Frac {
	l := lcm(x.b, y.b)
	return (&Frac{a: x.a*(l/x.b) + y.a*(l/y.b), b: l}).Update()
}

func fractionAddition(expression string) string {
	ans := &Frac{}
	E, op := []byte(expression), byte(' ')
	ans.a, E = nextInt(E)
	E = E[1:]
	ans.b, E = nextInt(E)
	ans.Update()
	for len(E) != 0 {
		tmp := &Frac{}
		op, E = E[0], E[1:]
		tmp.a, E = nextInt(E)
		E = E[1:]
		tmp.b, E = nextInt(E)
		if op == '-' {
			tmp.a = -tmp.a
		}
		ans = ans.Add(tmp.Update())
	}
	return strconv.FormatInt(int64(ans.a), 10) + "/" + strconv.FormatInt(int64(ans.b), 10)
}
func main() {
	fmt.Println(fractionAddition("-1/2+1/2"))
	fmt.Println(fractionAddition("-1/2+1/2+1/3"))
	fmt.Println(fractionAddition("1/3-1/2"))

}
