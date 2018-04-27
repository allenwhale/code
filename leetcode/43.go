package main

import "math/big"

import "fmt"
import "math"
import "bytes"

type Complex struct {
    r, i float64
}

func (c Complex) Add(x Complex) Complex {
    return Complex{c.r + x.r, c.i + x.i}
}
func (c Complex) Sub(x Complex) Complex {
    return Complex{c.r - x.r, c.i - x.i}
}
func (c Complex) Mulf(x float64) Complex {
    return Complex{c.r * x, c.i * x}
}
func (c Complex) Mul(x Complex) Complex {
    return Complex{c.r * x.r - c.i * x.i, c.r * x.i + c.i * x.r}
}
func (c Complex) Div(x float64) Complex {
    return Complex{c.r / x, c.i / x}
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func toArray(s string) []Complex{
    ss := []byte(s)
    for i := 0 ; i < len(ss) / 2 ; i++ {
        ss[i], ss[len(ss) - i - 1] = ss[len(ss) - i - 1], ss[i]
    }
    l := 1
    for l <= len(ss) / 5 + 1 {
        l <<= 1
    }
    res := make([]Complex, l)
    for i := 0 ; i < l ; i++ {
        for j := 4 ; j >= 0 ; j-- {
            if i * 5 + j < len(ss) {
                res[i] = res[i].Mulf(10.).Add(Complex{float64(ss[i * 5 + j]) - float64('0'), 0.})
            }
        }
    }
    return res
}

func reverse(s []Complex) {
    for i, j := 1, 0 ; i < len(s) ; i++ {
        for k := len(s) >> 1 ; ; k >>= 1 {
            j = j ^ k
            if (j & k) != 0 {
                break
            }
        }
        if i > j {
           s[i], s[j] = s[j], s[i]
        }
    }
}

func FFT(s []Complex, flag int) {
    reverse(s)
    for k := 2 ; k <= len(s) ; k <<= 1 {
        p0 := -math.Pi / float64(k >> 1) * float64(flag)
        unit_p0 := Complex{math.Cos(p0), math.Sin(p0)}
        for j := 0 ; j < len(s) ; j += k {
            unit := Complex{1.0, 0.}
            for i := j ; i < j + k / 2 ; i, unit = i + 1, unit.Mul(unit_p0) {
                t1, t2 := s[i], s[i + k / 2].Mul(unit)
                s[i], s[i + k / 2] = t1.Add(t2), t1.Sub(t2)
            }
        }
    }
    if flag == -1 {
        for i := 0 ; i < len(s) ; i++ {
            s[i] = s[i].Div(float64(len(s)))
        }
    }
}

func multiply(num1 string, num2 string) string {
    if num1 == "0" || num2 == "0" {
        return "0"
    }
    arr1, arr2 := toArray(num1), toArray(num2)
    arr3 := make([]Complex, max(len(arr1), len(arr2)) << 1)
    for len(arr1) < len(arr3) {
        arr1 = append(arr1, Complex{})
    }
    for len(arr2) < len(arr3) {
        arr2 = append(arr2, Complex{})
    }
    FFT(arr1, 1)
    FFT(arr2, 1)
    for i := 0 ; i < len(arr1) ; i++ {
        arr3[i] = arr1[i]
    }
    for i := 0 ; i < len(arr2) ; i++ {
        arr3[i] = arr3[i].Mul(arr2[i])
    }
    FFT(arr3, -1)
    arr4 := make([]int64, len(arr3))
    for i := 0 ; i < len(arr3) ; i++ {
        arr4[i] = int64(arr3[i].r + 0.5)
    }
    for i := 0 ; i < len(arr3) - 1 ; i++ {
        arr4[i + 1] += arr4[i] / 100000;
        arr4[i] %= 100000
    }
    var i int
    for i = len(arr4) - 1 ; arr4[i] == 0 ; i-- {}
    res := bytes.Buffer{}
    res.WriteString(fmt.Sprintf("%d", arr4[i]))
    for i = i - 1 ; i >= 0 ; i-- {
        res.WriteString(fmt.Sprintf("%05d", arr4[i]))
    }
    return res.String()
}

func main() {
    l := 100000;
    x := make([]byte, l)
    for i := 0 ; i < l ; i++ {
        x[i] = '1'
    }
    num1, num2 := string(x), string(x)
    a, b, c := big.NewInt(0), big.NewInt(0), big.NewInt(0)
    a.SetString(num1, 10)
    b.SetString(num2, 10)
    c.Mul(a, b)
    fmt.Println(c.String() == multiply(num1, num2))
}
