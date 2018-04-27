package main

import "fmt"


func getPermutation(n int, k int) string {
    fact := []int{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600}
    ans, used := make([]byte, n), make([]bool, n + 1)
    k--
    for i := 0 ; i < n ; i++ {
        tmp := k / fact[n - i - 1]
        for j := 1 ; j <= n ; j++ {
            if !used[j] {
                if tmp == 0 {
                    ans[i], used[j] = byte(j + int('0')), true
                    k %= fact[n - i - 1]
                    break
                }
                tmp--
            }
        }
    }
    return string(ans)
}

func main() {
    fmt.Println(getPermutation(3, 3))
}
