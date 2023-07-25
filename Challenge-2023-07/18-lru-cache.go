package main

type Item struct {
	key   int
	value int
	prev  *Item
	next  *Item
}

func newItem(key, value int) *Item {
	return &Item{
		key:   key,
		value: value,
		prev:  nil,
		next:  nil,
	}
}

type LRUCache struct {
	head *Item
	tail *Item
	cap  int
	m    map[int]*Item
}

func Constructor(capacity int) LRUCache {
	head, tail := newItem(-1, -1), newItem(-1, -1)
	head.next = tail
	tail.prev = head
	return LRUCache{
		head: head,
		tail: tail,
		cap:  capacity,
		m:    make(map[int]*Item),
	}
}

func (this *LRUCache) Get(key int) int {
	if _, ok := this.m[key]; ok {
		resItem := this.m[key]
		res := resItem.value
		delete(this.m, key)
		this.deleteItem(resItem)
		this.addItem(resItem)
		this.m[key] = this.head.next
		return res
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.m[key]; ok {
		oldItem := this.m[key]
		delete(this.m, key)
		this.deleteItem(oldItem)
	}
	if len(this.m) == this.cap {
		lastItem := this.tail.prev
		delete(this.m, lastItem.key)
		this.deleteItem(lastItem)
	}
	this.addItem(&Item{
		key:   key,
		value: value,
		prev:  nil,
		next:  nil,
	})
	this.m[key] = this.head.next
}

func (this *LRUCache) addItem(item *Item) {
	temp := this.head.next
	item.next = temp
	item.prev = this.head
	this.head.next = item
	temp.prev = item
}

func (this *LRUCache) deleteItem(item *Item) {
	prv, nxt := item.prev, item.next
	prv.next = nxt
	nxt.prev = prv
}
