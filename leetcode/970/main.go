package main

func powerfulIntegers(x int, y int, bound int) []int {
	ans := make([]int, 0)
	mp := make(map[int]bool)
	for i := 1; i < bound; i = i * x {
		for j := 1; i+j <= bound; j = j * y {
			if !mp[i+j] {
				mp[i+j] = true
				ans = append(ans, i+j)
			}
			if y == 1 {
				break
			}
		}
		if x == 1 {
			break
		}
	}
	return ans
}
func main() {

}
