#include "../header.h"

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        int m = l + (r - l) / 2;
        while (l < r) {
            m = l + (r - l) / 2;
            if (fit(weights, days, m)) {
                r = m;
            } else {
                l = m + 1;
            }            
        }
        return l;
    }

    bool fit(vector<int>& weights, int days, int capacity) {
        int d = 0, s = 0;
        for (int i = 0; i < weights.size(); ++i) {
            // no need to check weights[i] > capacity, the lower bound is already the maximum weight
            s += weights[i];
            if (s > capacity) {
                ++d;
                s = weights[i];
            }
            if (d > days) {
                return false;
            }
        }
        // the rest in "s" will be another day
        return d < days;
    }


   /**
    * below are not restricted to continuous items => not tested as well
       
    bool fit(vector<int>& weights, int days, int capacity) {
        vector<int> v(days, 0);
        return helper(weights, v, capacity, 0);
    }

    bool helper(vector<int>& weights, vector<int>& v, int capacity, int index) {
        if (index >= weights.size()) {
            return true;
        }
        bool res = false;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] + weights[index] <= capacity) {
                v[i] += weights[index];
                res |= helper(weights, v, capacity, index + 1);
                v[i] -= weights[index];
            }
        }
        return res;
    }
    */
};

int main() {
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    int capacity = 3;
    cout << Solution().fit(weights, days, capacity) << endl;
    return 0;
}