package main

func intersection(nums1 []int, nums2 []int) []int {
	mp := make(map[int]bool, len(nums1))
	for _, v := range nums1 {
		mp[v] = true
	}
	mp2 := make(map[int]bool, len(mp))
	for _, v := range nums2 {
		if mp[v] {
			mp2[v] = true
		}
	}
	ans := make([]int, 0, len(mp2))
	for k := range mp2 {
		ans = append(ans, k)
	}
	return ans
}
func main() {

}
