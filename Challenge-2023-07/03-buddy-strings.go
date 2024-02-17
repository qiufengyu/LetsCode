package main

func buddyStrings(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}
	n := len(s)
	idx1, idx2 := -1, -1
	for i := 0; i < n; i++ {
		if s[i] != goal[i] {
			if idx1 == -1 {
				idx1 = i
			} else if idx2 == -1 {
				idx2 = i
			} else {
				return false
			}
		}
	}
	if idx1 != -1 && idx2 != -1 {
		return s[idx1] == goal[idx2] && s[idx2] == goal[idx1]
	} else if idx1 == -1 && idx2 == -1 {
		// same string, to check if there are any repeated chars
		mp := make(map[rune]bool)
		for _, r := range s {
			mp[r] = true
		}
		return len(mp) != n
	}
	return false
}
