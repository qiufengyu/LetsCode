#include "header.h"

class Solution {
    vector<int> sum;
public:
    Solution(vector<int>& w) {
        sum = w;
        for (int i = 1; i < w.size(); i++) {
            sum[i] = sum[i-1] + w[i];
        }        
    }
    
    int pickIndex() {
        int pos = rand() % sum.back();
        int start = 0, end = sum.size() - 1;
        int mid = start + (end - start) / 2;
        while (start < end) {
            if (sum[mid] <= pos) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }
        return end;
    }
};


