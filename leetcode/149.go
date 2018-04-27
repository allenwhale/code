package main

import "fmt"

type Point struct {
	X int
	Y int
}

func gcd(a, b int) int {
	for {
		a %= b
		if a == 0 {
			break
		}
		b %= a
		if b == 0 {
			break
		}
	}
	return a + b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func maxPoints(points []Point) int {
	ans := 0
	for _, p1 := range points {
		ver, hor, dup, cnt := 0, 0, 0, map[Point]int{}
		for _, p2 := range points {
			if p1.X == p2.X && p1.Y == p2.Y {
				dup++
			} else {
				dx, dy := p1.X-p2.X, p1.Y-p2.Y
				if dx == 0 {
					ver++
				} else if dy == 0 {
					hor++
				} else {
					g := gcd(dx, dy)
					dx, dy = dx/g, dy/g
					if dx*dy < 0 {
						dx, dy = abs(dx), -abs(dy)
					} else {
						dx, dy = abs(dx), abs(dy)
					}
					cnt[Point{dx, dy}]++
				}
			}
		}
		now := max(ver, hor)
		for _, v := range cnt {
			if v > now {
				now = v
			}
		}
		if ans < now+dup {
			ans = now + dup
		}
	}
	return ans
}
func main() {
	fmt.Println(maxPoints([]Point{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}))
}
