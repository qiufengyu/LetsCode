#include "../header.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        // quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if (s < e) {
            int m = s + (e - s) / 2;
            mergeSort(nums, s, m);
            mergeSort(nums, m + 1, e);
            merge(nums, s, m, e);
        }
    }

    void merge(vector<int>& nums, int s, int m, int e) {
        vector<int> temp(e - s + 1);
        int i = s, j = m + 1, k = 0;
        while (i <= m && j <= e) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                ++k;
                ++i;
            } else {
                temp[k] = nums[j];
                ++j;
                ++k;
            }
        }
        while (i <= m) {
            temp[k] = nums[i];
            ++k;
            ++i;
        }
        while (j <= e) {
            temp[k] = nums[j];
            ++k;
            ++j;
        }
        for (int x = 0; x < k; ++x) {
            nums[s + x] = temp[x];
        }
    }

    // void quickSort(vector<int>& nums, int s, int e) {
    //     if (e > s) {            
    //         int m = partition(nums, s, e);
    //         quickSort(nums, s, m - 1);
    //         quickSort(nums, m + 1, e);
    //     }        
    // }

    // int partition(vector<int>& nums, int s, int e) {
    //     int p = nums[e];
    //     int l = s, h = e - 1;
    //     while (l <= h) {
    //         while (l < e && nums[l] < p) {
    //             ++l;
    //         }
    //         while (h >= s && nums[h] >= p) {
    //             --h;
    //         }
    //         if (l < h) {
    //             swap(nums[l], nums[h]);
    //         }
    //     }
    //     swap(nums[l], nums[e]);
    //     return l;
    // }
};

int main() {
    vector<int> nums {5,1,1,2,0,0};
    vector<int> res = Solution().sortArray(nums);
    print_vector<int>(res);
    return 0;
}