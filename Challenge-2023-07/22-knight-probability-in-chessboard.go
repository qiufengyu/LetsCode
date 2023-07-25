package main

func knightProbability(n int, k int, row int, column int) float64 {
	dirs := [8][2]int{{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}}
	dp1, dp2 := make([][]float64, n), make([][]float64, n)
	for i := 0; i < n; i++ {
		dp1[i] = make([]float64, n)
		dp2[i] = make([]float64, n)
	}
	dp1[row][column] = 1.0
	for i := 0; i < k; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				dp2[j][k] = 0.0
				for d := 0; d < 8; d++ {
					prevJ, prevK := j-dirs[d][0], k-dirs[d][1]
					if prevJ >= 0 && prevK >= 0 && prevJ < n && prevK < n {
						dp2[j][k] += dp1[prevJ][prevK] / 8.0
					}
				}
			}
		}
		dp1, dp2 = dp2, dp1
		// newDp := make([][]float64, n)
		// for i := 0; i < n; i++ {
		// 	newDp[i] = make([]float64, n)
		// 	newDp[i] = dp1[i]
		// 	dp1[i] = dp2[i]
		// 	dp2[i] = newDp[i]
		// }
	}
	res := 0.0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			res += dp1[i][j]
		}
	}
	return res
}
