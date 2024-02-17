package main

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func maxConsecutiveAnswers(answerKey string, k int) int {
	left, right := 0, 0
	ts, fs := 0, 0
	res := 1
	for right < len(answerKey) {
		if answerKey[right] == 'T' {
			ts++
		} else {
			fs++
		}
		if ts <= k || fs <= k {
			res = max2(res, right-left+1)
		} else {
			for ts > k && fs > k {
				if answerKey[left] == 'T' {
					ts--
				} else {
					fs--
				}
				left++
			}
		}
		right++
	}
	return res
}
