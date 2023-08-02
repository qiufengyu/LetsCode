package main

type Item struct {
	a, b int
}

func soupServings(n int) float64 {
	// magic number: it is proved that if n > 4451, then P(A) ~= 1
	if n > 4451 {
		return 1.0
	}
	n = (n + 24) / 25
	m := make(map[Item]float64)
	return dp(n, n, m)
}

func dp(a int, b int, m map[Item]float64) float64 {
	if a <= 0 && b <= 0 {
		return 0.5
	}
	if a <= 0 {
		return 1.0
	}
	if b <= 0 {
		return 0.0
	}
	// since
	key := Item{a: a, b: b}
	if _, ok := m[key]; ok {
		return m[key]
	}
	m[key] = 0.25 * (dp(a-4, b, m) + dp(a-3, b-1, m) + dp(a-2, b-2, m) + dp(a-1, b-3, m))
	return m[key]
}
