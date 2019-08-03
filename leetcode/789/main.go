package main

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func escapeGhosts(ghosts [][]int, target []int) bool {
	L := Abs(target[0]) + Abs(target[1])
	for _, g := range ghosts {
		if Abs(g[0]-target[0])+Abs(g[1]-target[1]) <= L {
			return false
		}
	}
	return true
}
func main() {

}
