package main

import "math"

func isSquare(n int) bool {
	sq := int(math.Sqrt(float64(n)) + 0.5)
	return sq*sq == n
}
func numSquares(n int) int {
	if isSquare(n) {
		return 1
	}
	for n&3 == 0 {
		n = n >> 2
	}
	if n%8 == 7 {
		return 4
	}
	for i := 1; i*i <= n; i++ {
		if isSquare(n - i*i) {
			return 2
		}
	}
	return 3
}
func main() {

}
