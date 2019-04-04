package main

func matrixReshape(nums [][]int, r int, c int) [][]int {
	if r*c != len(nums)*len(nums[0]) {
		return nums
	}
	cc := len(nums[0])
	res := make([][]int, r)
	for i := 0; i < r; i++ {
		res[i] = make([]int, c)
	}
	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			id := i*c + j
			res[i][j] = nums[id/cc][id%cc]
		}
	}
	return res
}
func main() {

}
