package main

func canVisitAllRooms(rooms [][]int) bool {
	vis, cnt := make([]bool, len(rooms)), 0
	vis[0] = true
	q := []int{0}
	for len(q) > 0 {
		n := q[0]
		q, cnt = q[1:], cnt+1
		for _, v := range rooms[n] {
			if vis[v] == false {
				vis[v] = true
				q = append(q, v)
			}
		}
	}
	return cnt == len(rooms)
}
func main() {

}
