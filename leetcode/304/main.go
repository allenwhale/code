package main

type NumMatrix struct {
	sub [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	res := NumMatrix{}
	if len(matrix) == 0 {
		return res
	}
	res.sub = make([][]int, len(matrix))
	for i := 0; i < len(matrix); i++ {
		res.sub[i] = make([]int, len(matrix[0]))
	}
	res.sub[0][0] = matrix[0][0]
	for i := 1; i < len(matrix); i++ {
		res.sub[i][0] = res.sub[i-1][0] + matrix[i][0]
	}
	for i := 1; i < len(matrix[0]); i++ {
		res.sub[0][i] = res.sub[0][i-1] + matrix[0][i]
	}
	for i := 1; i < len(matrix); i++ {
		for j := 1; j < len(matrix[0]); j++ {
			res.sub[i][j] = res.sub[i-1][j] + res.sub[i][j-1] - res.sub[i-1][j-1] + matrix[i][j]
		}
	}
	return res
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	res := this.sub[row2][col2]
	if row1 > 0 {
		res = res - this.sub[row1-1][col2]
	}
	if col1 > 0 {
		res = res - this.sub[row2][col1-1]
	}
	if row1 > 0 && col1 > 0 {
		res = res + this.sub[row1-1][col1-1]
	}
	return res
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
func main() {

}
