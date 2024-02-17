#include "../header.h"

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), d = n / 4;
        int i = 0;
        while (i < n) {
            if (i + d < n && arr[i] == arr[i + d]) {
                break;
            }
            i++;
        }
        return i < n ? arr[i] : arr[n-1];
    }
};