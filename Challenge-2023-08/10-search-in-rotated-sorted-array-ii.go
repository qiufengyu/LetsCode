package main

func search(nums []int, target int) bool {
	l, r := 0, len(nums)-1
	m := l + (r-l)/2
	for l <= r {
		m = l + (r-l)/2
		cand := nums[m]
		if cand == target {
			return true
		}
		// special case when we see out of order numbers, below "if" is true
		if nums[l] == nums[m] && nums[r] == nums[m] {
			l++
			r--
		} else {
			if nums[l] <= nums[m] {
				if cand < target {
					l = m + 1
				} else {
					if target < nums[l] {
						l = m + 1
					} else {
						r = m - 1
					}
				}
			} else {
				if cand > target {
					r = m - 1
				} else {
					if nums[r] < target {
						r = m - 1
					} else {
						l = m + 1
					}
				}
			}
		}
	}
	return false
}
