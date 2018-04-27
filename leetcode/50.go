package main

func myPow(x float64, n int) float64 {
    sign := true
    if n < 0 {
        n = -n
        sign = false
    }
    ans := 1.
    for n != 0 {
        if (n & 1) != 0 {
            ans *= x
        }
        x *= x
        n >>= 1
    }
    if sign {
        return ans
    }
    return 1. / ans
}

func main() {
}
