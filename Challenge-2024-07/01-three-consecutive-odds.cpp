#include "../header.h"

inline bool odd(int x) {
    return (x & 1) == 1;
}

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++) {
            if (odd(arr[i])) {
                if (odd(arr[i+1])) {
                    if (odd(arr[i+2])) {
                        return true;
                    } else {
                        i += 2;
                    }
                } else {
                    i++;
                }
            }
        }
        return false;
    }
};