#include "../header.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int m = l + (r - l) / 2;
        while (l < r) {
            m = l + (r - l) / 2;
            if (fit(piles, m, h)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

    bool fit(vector<int>& piles, int m, int h) {
        int hr = 0;
        for (int i = 0; i < piles.size(); ++i) {
            hr += (piles[i] + m - 1) / m;
        }
        return hr <= h;
    }
};