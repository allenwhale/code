package main

func containsDuplicate(nums []int) bool {
	mp := make(map[int]bool)
	for _, v := range nums {
		if mp[v] {
			return true
		}
		mp[v] = true
	}
	return false
}
func main() {

}
