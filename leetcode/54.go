package main

import "github.com/kr/pretty"

func spiralOrder(matrix [][]int) []int {
    if len(matrix) == 0 {
        return []int{}
    }
    n, m := len(matrix), len(matrix[0])
    u, d, l, r := 0, n - 1, 0, m - 1
    ans := []int{}
    for u <= d && l <= r {
        for i := l ; i <= r ; i++ {
            ans = append(ans, matrix[u][i])
        }
        for i := u + 1 ; i <= d ; i++ {
            ans = append(ans, matrix[i][r])
        }
        if u == d {
            break
        }
        for i := r - 1 ; i >= l ; i-- {
            ans = append(ans, matrix[d][i])
        }
        if l == r {
            break
        }
        for i := d - 1 ; i > u ; i-- {
            ans = append(ans, matrix[i][l])
        }
        u, d, l, r = u + 1, d - 1, l + 1, r - 1
    }
    return ans
}

func main() {
    matrix := [][]int{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {14, 15, 16},
    }
    pretty.Println(matrix)
    pretty.Println(spiralOrder(matrix))
}
