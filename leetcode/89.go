package main

func grayCode(n int) []int {
	res := make([]int, 1<<uint(n))
	for i := 0; i < 1<<uint(n); i += 1 {
		res[i] = (i >> 1) ^ i
	}
	return res
}
func main() {}
