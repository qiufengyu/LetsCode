#include "../header.h"

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;
        for (int x: arr) {
            ++m[x];
        }
        for (auto& [k, v]: m) {
            if (v < 0) {
                return false;
            }
            if (v > 0) {
                if (k > 0) {
                    if (m.count(k*2) <= 0) {
                        return false;
                    }
                    m[k*2] -= v;
                } else if (k == 0 && v % 2 != 0) {
                    return false;
                } else { // k < 0
                    if (k % 2 != 0) { // k is odd & negative
                        return false;
                    }
                    if (m.count(k / 2) <= 0) {
                        return false;
                    }
                    m[k/2] -= v;
                }
            }
        }
        return true;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().canReorderDoubled(v) << endl;
    return 0;
}