#include "../header.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        bool up = arr[0] < arr[1], down = false;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (up && !down && arr[i] < arr[i+1]) {
                continue;
            }
            if (down && !up && arr[i] > arr[i+1]) {
                continue;
            }
            if (up && !down && arr[i] > arr[i+1]) {
                up = false;
                down = true;
                continue;
            }
            return false;
        }
        return !up && down;
    }
};