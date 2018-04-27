package main
import "fmt"
import "github.com/kr/pretty"
func setZeroes(matrix [][]int)  {
    n, m, row0, col0 := len(matrix), len(matrix[0]), false, false
    for i := 0 ; i < n ; i++ {
        if matrix[i][0] == 0 {
            col0 = true
            break
        }
    }
    for j := 0 ; j < m ; j++ {
        if matrix[0][j] == 0 {
            row0 = true
            break
        }
    }
    for i := 1 ; i < n ; i++ {
        for j := 1 ; j < m ; j++ {
            if matrix[i][j] == 0 {
                matrix[0][j], matrix[i][0] = 0, 0
            }
        }
    }
    for i := 1 ; i < n ; i++ {
        if matrix[i][0] == 0 {
            for j := 0 ; j < m ; j++ {
                matrix[i][j] = 0;
            }
        }
    }
    for j := 1 ; j < m ; j++ {
        if matrix[0][j] == 0 {
            for i := 0 ; i < n ; i++ {
                matrix[i][j] = 0;
            }
        }
    }
    if col0 {
        for i := 0 ; i < n ; i++ {
            matrix[i][0] = 0
        }
    }
    if row0 {
        for j := 0 ; j < m ; j++ {
            matrix[0][j] = 0
        }
    }
}

func main() {
    matrix := [][]int{
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    }
    setZeroes(matrix)
    fmt.Println(matrix)
}
