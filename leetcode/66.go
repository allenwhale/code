package main
//import "github.com/kr/pretty"

func plusOne(digits []int) []int {
    n := len(digits) - 1
    digits[n]++
    for n > 0 && digits[n] >= 10 {
        digits[n], digits[n - 1], n = 0, digits[n - 1] + 1, n - 1
    }
    if n == 0 && digits[0] >= 10 {
        digits[0] = 0
        digits = append([]int{1}, digits...)
    }
    return digits
}

func main() {
    plusOne([]int{0})
}
