package main

import "fmt"

func mySqrt(x int) int {
    l, r, ans := 0, x, 0
    for l <= r {
        mid := (l + r) >> 1
        if mid * mid <= x {
            ans, l = mid, mid + 1
        } else {
            r = mid - 1
        }
    }
    return ans
}

func main() {
    for i := 0 ; i < 10 ; i++ {
        fmt.Println(i, mySqrt(i))
    }
}
