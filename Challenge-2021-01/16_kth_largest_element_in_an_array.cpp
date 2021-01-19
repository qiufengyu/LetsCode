#include "../header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1, nums.size()-k);
        return nums[nums.size()-k];
    }

    void quickSort(vector<int>& nums, int start, int end, int k) {
        if (start < end) {
            int p = partition(nums, start, end);
            if (k <= p) {
                quickSort(nums, start, p - 1, k);
            } else {
                quickSort(nums, p + 1, end, k);
            }
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[end];
        int i = start, j = start;
        while (j <= end) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
        swap(nums[i], nums[end]);
        return i;
    }
};