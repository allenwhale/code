package main
import "github.com/kr/pretty"

func uniquePaths(m int, n int) int {
    res := 1
    if m > n {
        m, n = n, m
    }
    n, m = n - 1, m - 1
    for i, j := n + 1, 1 ; i <= m + n ; i, j = i + 1, j + 1 {
        res *= i
        res /= j
    }
    return res
}

func main() {
    pretty.Println(uniquePaths(3, 2))
}
