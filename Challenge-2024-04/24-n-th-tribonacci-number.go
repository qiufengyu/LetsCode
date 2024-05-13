package main

func tribonacci(n int) int {
	if n == 0 || n == 1 {
		return n
	}
	t1, t2, t3 := 0, 1, 1
	for i := 2; i < n; i += 1 {
		tmp3, tmp2 := t3, t2
		t3 = t3 + t2 + t1
		t2 = tmp3
		t1 = tmp2
	}
	return t3
}
