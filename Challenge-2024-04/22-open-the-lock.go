package main

func openLock(deadends []string, target string) int {
	ds := make(map[string]bool)
	vs := make(map[string]bool)
	for _, d := range deadends {
		ds[d] = true
	}
	if _, ok := ds["0000"]; ok {
		return -1
	}
	res := 0
	start := "0000"
	vs["0000"] = true
	queue := make([]string, 0)
	queue = append(queue, start)
	for len(queue) > 0 {
		sz := len(queue)
		for sz > 0 {
			frt := queue[0]
			if frt == target {
				return res
			}
			queue = queue[1:]
			vs[frt] = true
			nxt := nextLock(frt, ds, vs)
			for _, l := range nxt {
				queue = append(queue, l)
			}
			sz -= 1
		}
		res += 1
	}
	return -1
}

func nextNumber(n byte) []byte {
	res := make([]byte, 2)
	if n == '0' {
		res[0] = '9'
		res[1] = '1'
	} else if n == '9' {
		res[0] = '8'
		res[1] = '0'
	} else {
		res[0] = n - 1
		res[1] = n + 1
	}
	return res
}

func nextLock(frt string, ds, vs map[string]bool) []string {
	nxt := make([]string, 0)
	for i, c := range frt {
		ns := []rune(frt)
		nc := nextNumber(byte(c))
		ns[i] = rune(nc[0])
		if _, ok1 := ds[string(ns)]; !ok1 {
			if _, ok2 := vs[string(ns)]; !ok2 {
				nxt = append(nxt, string(ns))
				vs[string(ns)] = true
			}
		}
		ns[i] = rune(nc[1])
		if _, ok1 := ds[string(ns)]; !ok1 {
			if _, ok2 := vs[string(ns)]; !ok2 {
				nxt = append(nxt, string(ns))
				vs[string(ns)] = true
			}
		}
	}
	return nxt
}
