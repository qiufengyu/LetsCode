#include "header.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        if (sz == 0) {
            return 0;
        }
        int s = 0, mid = 0, e = sz - 1;
        int res = 0;
        while (s <= e) {
            mid = s + (e - s) / 2;
            res = citations[mid];
            // 1. >= h papers has >= h citations
            // 2. <= sz - h papers has <= h citations
            if (sz - mid > res) { // violate 1, h should be lower, mid grow
                s = mid + 1;
            } else { // h could be larger, mid decrease
                e = mid - 1;
            }
        }
        return sz - s;
    }
};

int main() {
    vector<int> c {1,10,10,10};
    cout << Solution().hIndex(c) << endl;
    return 0;
}