package main

func minimumReplacement(nums []int) int64 {
	n := len(nums)
	prev := nums[n-1]
	var res int64 = 0
	for i := n - 2; i >= 0; i-- {
		num := nums[i]
		breaks := (num + prev - 1) / prev
		res += int64(breaks - 1)
		prev = num / breaks
	}
	return res
}
