package main
import "fmt"
func climbStairs(n int) int {
    a, b := 1, 1
    for i := 0 ; i < n ; i++ {
        a, b = b, a + b
    }
    return a
}
func main() {
    for i := 1 ; i < 10 ; i++ {
        fmt.Println(i, climbStairs(i))
    }
}
