package main


import "github.com/kr/pretty"
import "fmt"

func rotate(matrix [][]int)  {
    m := matrix
    n := len(matrix)
    for i := 0 ; i < n - 1 ; i++ {
        for j := i ; j < n - i - 1 ; j++ {
            ai, aj := i, j
            bi, bj := j, n - i - 1
            ci, cj := n - i - 1, n - j - 1
            di, dj := n - j - 1, i
            fmt.Println(ai,aj,bi,bj,ci,cj,di,dj)
            m[ai][aj], m[bi][bj], m[ci][cj], m[di][dj] = m[di][dj], m[ai][aj], m[bi][bj], m[ci][cj]
        }
    }
}

func main() {
    m := [][]int{
        {1, 2, 3, 4},
        {4, 5, 6, 7},
        {7, 8, 9, 10},
        {10, 11, 12, 13},
    }
    rotate(m)
    pretty.Println(m)
}
