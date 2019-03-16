package main

func find(p []int, x int) int {
	if p[x] == x {
		return x
	}
	p[x] = find(p, p[x])
	return p[x]
}
func union(p []int, a, b int) {
	p[find(p, a)] = find(p, b)
}

func findCircleNum(M [][]int) int {
	p := make([]int, len(M))
	for i := 0; i < len(p); i++ {
		p[i] = i
	}
	for i := 0; i < len(M); i++ {
		for j := i + 1; j < len(M); j++ {
			if M[i][j] == 1 {
				union(p, i, j)
			}
		}
	}
	ans := 0
	for i := 0; i < len(M); i++ {
		if i == find(p, i) {
			ans++
		}
	}
	return ans
}
func main() {

}
