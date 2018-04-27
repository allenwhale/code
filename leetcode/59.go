package main

import "github.com/kr/pretty"

func generateMatrix(n int) [][]int {
    matrix := make([][]int, n)
    for i := 0 ; i < n ; i++ {
        matrix[i] = make([]int, n)
    }
    u, d, l, r, cnt := 0, n - 1, 0, n - 1, 1
    for u <= d && l <= r {
        for i := l ; i <= r ; i++ {
            matrix[u][i], cnt = cnt, cnt + 1
        }
        for i := u + 1 ; i <= d ; i++ {
            matrix[i][r], cnt = cnt, cnt + 1
        }
        if u == d {
            break
        }
        for i := r - 1 ; i >= l ; i-- {
            matrix[d][i], cnt = cnt, cnt + 1
        }
        if l == r {
            break
        }
        for i := d - 1 ; i > u ; i-- {
            matrix[i][l], cnt = cnt, cnt + 1
        }
        u, d, l, r = u + 1, d - 1, l + 1, r - 1
    }
    return matrix
}

func main() {
    pretty.Println(generateMatrix(3))
    pretty.Println(generateMatrix(4))
    pretty.Println(generateMatrix(0))
}

