#include "../header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1, s = 0;
        while (i < j) {
            s = numbers[i] + numbers[j];
            if (s == target) {
                return {i, j};
            } else if (s > target) {
                --j;
            } else {
                ++i;
            }
        }
        return {i, j};
    }
};