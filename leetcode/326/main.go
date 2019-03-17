package main

import "math"

func isPowerOfThree(n int) bool {
	if n == 0 {
		return false
	}
	return n == int(math.Pow(3., float64(int64(math.Log(float64(n))/math.Log(3.)+0.5)))+0.5)
}
func main() {

}
