#include "../header.h"

class Solution {
    void quickSort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int p = partition(nums, start, end);
            quickSort(nums, start, p - 1);
            quickSort(nums, p + 1, end);
        }        
    }

    int partition(vector<int>& nums, int start, int end) {
        int ps = start, pe = end;
        int pivot = nums[end];
        end -= 1;
        cout << "pivot = " << pivot << endl;
        cout << "start = " << start << ", end = " << end << endl;
        while (start < end) {
            while (start < pe && nums[start] <= pivot) {
                start++;
            }
            while (end > ps && nums[end] > pivot) {
                end--;
            }
            if (start < end) {
                swap(nums[start], nums[end]);
            }
        }
        // print_vector<int>(nums);
        if (start < pe && nums[pe] < nums[start]) {
            swap(nums[pe], nums[start]);
            cout << "swap " << start << ", " << pe << ", returning " << start << endl;
            print_vector<int>(nums);
            return start;
        }
        print_vector<int>(nums);
        cout << "returning " << pe << endl;
        return pe;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    vector<int> nums {5,1,1,2,0,0};
    auto res = Solution().sortArray(nums);
    print_vector<int>(res);
    return 0;
}