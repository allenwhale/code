package main

func sumEvenAfterQueries(A []int, queries [][]int) []int {
	ans, sum := make([]int, len(queries)), 0
	for _, v := range A {
		if v%2 == 0 {
			sum = sum + v
		}
	}
	for i, q := range queries {
		v, idx := q[0], q[1]
		if (v%2 == 0) == (A[idx]%2 == 0) {
			if A[idx]%2 == 0 {
				sum, A[idx] = sum-A[idx]+(A[idx]+v), A[idx]+v
				ans[i] = sum
			} else {
				sum, A[idx] = sum+(A[idx]+v), A[idx]+v
				ans[i] = sum
			}
		} else {
			if A[idx]%2 == 0 {
				sum, A[idx] = sum-A[idx], A[idx]+v
				ans[i] = sum
			} else {
				A[idx] = A[idx] + v
				ans[i] = sum
			}
		}
	}
	return ans
}
func main() {

}
