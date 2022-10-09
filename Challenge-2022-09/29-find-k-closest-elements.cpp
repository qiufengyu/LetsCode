#include "../header.h"

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto xit = lower_bound(arr.begin(), arr.end(), x);
        vector<int> res;
        if (xit == arr.end()) {
            return vector<int>(arr.end() - k, arr.end());
        }
        if (xit == arr.begin()) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        auto xprev = xit - 1;
        int ok = k;
        while (k > 0) {
            if (abs(*xprev - x) < abs(*xit - x) || (abs(*xprev - x) == abs(*xit - x) && *xprev < *xit)) {
                cout << *xprev << endl;
                res.insert(res.begin(), *xprev);
                if (xprev == arr.begin()) {
                    int rest = ok - res.size();
                    while (rest > 0) {
                        res.push_back(*xit);
                        ++xit;
                        --rest;
                    }
                    return res;
                }
                xprev--;
            } else {
                res.push_back(*xit);
                cout << *xit << endl;
                ++xit;
                if (xit == arr.end()) {
                    int rest = ok - res.size();
                    while (rest > 0) {
                        res.insert(res.begin(), *xprev);
                        --xprev;
                        --rest;
                    }
                    return res;
                }                
            }            
            --k;
        }
        return res;
    }
};

int main() {
    string s;
    int k, x;
    cin >> s;
    cin >> k >> x;
    vector<int> arr = stringToIntegerVector(s);
    vector<int> res = Solution().findClosestElements(arr, k, x);
    print_vector<int>(res);
    return 0;
}