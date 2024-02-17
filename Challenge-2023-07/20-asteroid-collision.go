package main

func asteroidCollision(asteroids []int) []int {
	var res []int
	for i := 0; i < len(asteroids); i++ {
		if asteroids[i] > 0 {
			res = append(res, asteroids[i])
		} else if len(res) == 0 || res[len(res)-1] < 0 {
			res = append(res, asteroids[i])
		} else if res[len(res)-1] <= (-asteroids[i]) {
			if res[len(res)-1] < (-asteroids[i]) {
				i--
			}
			res = res[:len(res)-1]
		}
	}
	return res
}
