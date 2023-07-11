package main

func singleNumber(nums []int) int {
	ones, twos := 0, 0
	n := len(nums)
	for i := 0; i < n; i++ {
		ones = (ones ^ nums[i]) & (^twos)
		twos = (twos ^ nums[i]) & (^ones)
	}
	return ones
}
