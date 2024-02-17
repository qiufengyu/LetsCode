#include "../header.h"

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (int i = 0; i < left.size(); i++) {
            res = max(res, left[i]);
        }
        for (int j = 0; j < right.size(); j++) {
            res = max(res, n - right[j]);
        }
        return res;
    }
};