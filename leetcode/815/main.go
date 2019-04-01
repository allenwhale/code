package main

func check(a, b map[int]bool) bool {
	if len(a) > len(b) {
		a, b = b, a
	}
	for v := range a {
		if b[v] {
			return true
		}
	}
	return false
}

func numBusesToDestination(routes [][]int, S int, T int) int {
	if S == T {
		return 0
	}
	R := make([]map[int]bool, len(routes))
	for i, route := range routes {
		R[i] = make(map[int]bool, len(route))
		for _, v := range route {
			R[i][v] = true
		}
	}
	G := make([][]int, len(routes))
	for i := 0; i < len(routes); i++ {
		G[i] = make([]int, 0)
	}
	for i := 0; i < len(routes); i++ {
		for j := i + 1; j < len(routes); j++ {
			if check(R[i], R[j]) {
				G[i] = append(G[i], j)
				G[j] = append(G[j], i)
			}
		}
	}
	q := make([]int, 0)
	t := make(map[int]bool)
	dis := make(map[int]int, len(G))
	for i := 0; i < len(routes); i++ {
		if R[i][S] {
			q = append(q, i)
			dis[i] = 1
		}
		if R[i][T] {
			t[i] = true
		}
	}
	for len(q) != 0 {
		n := q[0]
		if t[n] {
			return dis[n]
		}
		q = q[1:]
		for _, v := range G[n] {
			if _, ok := dis[v]; !ok {
				dis[v] = dis[n] + 1
				q = append(q, v)
			}
		}
	}
	return -1
}
func main() {

}
