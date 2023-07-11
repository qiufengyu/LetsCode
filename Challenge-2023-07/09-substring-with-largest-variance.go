package main

func max2(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func largestVariance(s string) int {
	count1, count2 := 0, 0
	maxVar := 0
	charSet := make(map[byte]bool)
	for i := 0; i < len(s); i++ {
		charSet[s[i]] = true
	}
	for runs := 0; runs < 2; runs++ {
		for b1, _ := range charSet {
			for b2, _ := range charSet {
				if b1 == b2 {
					continue
				}
				count1, count2 = 0, 0
				for i := 0; i < len(s); i++ {
					letter := s[i]
					if letter == b1 {
						count1++
					} else if letter == b2 {
						count2++
					}
					if count1 < count2 {
						count1, count2 = 0, 0
					} else if count1 > 0 && count2 > 0 {
						maxVar = max2(maxVar, count1-count2)
					}
				}
			}
		}
		runes := []rune(s)
		for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
			runes[i], runes[j] = runes[j], runes[i]
		}
		s = string(runes)
	}
	return maxVar
}
