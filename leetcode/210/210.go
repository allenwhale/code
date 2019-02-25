package main

func findOrder(numCourses int, prerequisites [][]int) []int {
	ans, g, deg := []int{}, make([][]int, numCourses), make([]int, numCourses)
	for _, p := range prerequisites {
		g[p[1]] = append(g[p[1]], p[0])
		deg[p[0]] = deg[p[0]] + 1
	}
	queue := []int{}
	for i := 0; i < numCourses; i = i + 1 {
		if deg[i] == 0 {
			queue = append(queue, i)
		}
	}
	for len(queue) != 0 {
		n := queue[0]
		queue = queue[1:]
		ans = append(ans, n)
		for _, v := range g[n] {
			deg[v] = deg[v] - 1
			if deg[v] == 0 {
				queue = append(queue, v)
			}
		}
	}
	if len(ans) != numCourses {
		return []int{}
	}
	return ans
}
func main() {

}
