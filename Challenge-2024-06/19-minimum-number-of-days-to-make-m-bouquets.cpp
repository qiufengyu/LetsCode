#include "../header.h"

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        size_t n = bloomDay.size();
        if ((size_t)m * k > n) {
            return -1;
        }
        int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int x = (l + r) / 2, bouquets = 0, count = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= x) {
                    count++;
                } else {
                    bouquets += (count / k);
                    count = 0;
                }
            }
            bouquets += (count / k);
            if (bouquets >= m) {
                r = x;
            } else {
                l = x + 1;
            }
        }
        return r;
    }
};

int main() {
    vector<int> bd{1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << Solution().minDays(bd, m, k) << endl;
    return 0;
}