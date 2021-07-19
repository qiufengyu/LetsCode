#include "../header.h"

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> res;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) {
            return {-1, -1};
        }
        if (sum == 0) {
            return {0, 2};
        }
        int tail0s = 0;
        int sz = arr.size();
        for (int i = sz - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                tail0s++;
            }
            else {
                break;
            }
        }
        int ones = 0;
        vector<int> v;
        string t1, t2;
        for (int i = 0; i < sz; ++i) {
            ones+= arr[i];
            if (!t1.empty() || arr[i] == 1) {
                t1 += ('0' + arr[i]);
            }
            if (ones == sum / 3) {
                for (int j = 0; j < tail0s; ++j) {
                    ++i;
                    if ( i >= sz || arr[i] == 1) {
                        return {-1, -1};
                    }
                    t1 += '0';
                }
                if (!t2.empty() && t2 != t1) {
                    return {-1, -1};
                }
                t2 = t1;
                t1.clear();
                ones = 0;
                res.push_back(i);
            }            
        }
        return {res[0], 1 + res[1]};
    }
};