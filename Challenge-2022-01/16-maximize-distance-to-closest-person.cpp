#include "../header.h"

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int zs = 0, res = 0, sz = seats.size();
        int si = 0, ej = sz - 1;
        while (si < sz && seats[si] == 0) {
            ++si;
        }
        res = si;
        while (ej >= 0 && seats[ej] == 0) {
            --ej;
        }
        res = max(res, sz - ej - 1);
        for (int i = si; i <= ej; ++i) {
            if (seats[i] == 0) {
                ++zs;
            } else {
                res = max(res, (1 + zs) / 2);
                zs = 0;
            }
        }
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().maxDistToClosest(v) << endl;
    return 0;
}