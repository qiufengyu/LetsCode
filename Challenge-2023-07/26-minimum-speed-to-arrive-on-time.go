package main

import "math"

func test(dist []int, n int, hour float64, speed int) bool {
	hr := 0.0
	for i := 0; i < n-1; i++ {
		hr += math.Ceil(float64(dist[i]) / float64(speed))
	}
	hr += float64(dist[n-1]) / float64(speed)
	return hr <= hour
}

func minSpeedOnTime(dist []int, hour float64) int {
	if float64(len(dist)-1) >= hour {
		return -1
	}
	n := len(dist)
	l, h, m := 1, 10000000, 5000000
	for l < h {
		m = (l + h) / 2
		if test(dist, n, hour, m) {
			h = m
		} else {
			l = m + 1
		}
	}
	return h
}
