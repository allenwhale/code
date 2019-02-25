package main

import (
	"container/list"
	"fmt"
)

type LRUCache struct {
	capacity   int
	cache      map[int]int
	cache2List map[int]*list.Element
	history    *list.List
}

func Constructor(capacity int) LRUCache {
	LRU := LRUCache{
		capacity:   capacity,
		cache:      make(map[int]int, capacity),
		cache2List: make(map[int]*list.Element, capacity),
		history:    list.New(),
	}
	return LRU
}

func (this *LRUCache) Refresh(key int) {
	if this.cache2List[key] != nil {
		this.history.Remove(this.cache2List[key])
	}
	this.cache2List[key] = this.history.PushFront(key)
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.cache[key]; ok {
		this.Refresh(key)
		return v
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.cache[key]; !ok && len(this.cache) == this.capacity {
		e := this.history.Back()
		this.history.Remove(e)
		delete(this.cache, e.Value.(int))
		delete(this.cache2List, e.Value.(int))
	}
	this.cache[key] = value
	this.Refresh(key)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
func main() {
	obj := Constructor(2)
	fmt.Println(obj.Get(1))
	obj.Put(1, 10)
	obj.Put(2, 20)
	obj.Put(3, 30)
	fmt.Println(obj.Get(1))
	fmt.Println(obj.Get(2))
	fmt.Println(obj.Get(3))
}
