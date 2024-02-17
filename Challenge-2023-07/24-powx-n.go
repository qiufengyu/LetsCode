package main

func abs(n int) uint {
	if n > 0 {
		return uint(n)
	}
	return uint(-n)
}

func sign(n int) int {
	if n > 0 {
		return 1
	}
	return -1
}

func myPow(x float64, n int) float64 {
	nn, sign := abs(n), sign(n)
	res := 1.0
	for nn > 0 {
		if (nn & 1) != 0 {
			res *= x
		}
		nn >>= 1
		x = x * x
	}
	if sign == -1 {
		res = 1.0 / res
	}
	return res
}
