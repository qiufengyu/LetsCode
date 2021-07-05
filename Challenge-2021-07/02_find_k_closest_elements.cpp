#include "../header.h"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int sz = arr.size();
        auto lb = lower_bound(arr.begin(), arr.end(), x);
        if (lb == arr.end()) {
            for (int i = 0; i < k; ++i) {            
                res.push_back(arr[sz-(k-i)]);
            }
            return res;
        }
        if (lb == arr.begin()) {
            for (int i = 0; i < k; ++i) {
                res.push_back(arr[i]);
            }
            return res;
        }
        auto prev = lb - 1;
        for (int i = 0; i < k; ++i) {
            if (prev == arr.end()) {
                res.push_back(*lb);
                lb++;
                continue;
            }
            if (lb == arr.end()) {
                res.insert(res.begin(), *prev);
                prev--;
                continue;
            }
            if ((*lb - x) >= (x - *prev)) {
                res.insert(res.begin(), *prev);
                if (prev == arr.begin()) {
                    prev = arr.end();
                } else {
                    prev--;
                }
            } else {
                res.push_back(*lb);
                lb++;
            }
        }        
        return res;
    }


    vector<int> findClosestElements2(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};

int main() {
    vector<int> arr {1,2,3,4,5};
    int k = 4;
    int x = 3;
    auto res = Solution().findClosestElements(arr, k, x);
    print_vector<int>(res);
    return 0;
}