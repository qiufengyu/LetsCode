#include "../header.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int s = 0, e = sz - 1, count = 0;
        while (s < sz && flowerbed[s] == 0) {
            ++s;
        }
        count += (s / 2);
        while (e >= 0 && flowerbed[e] == 0) {
            --e;
        }
        // all zeros
        if (s == sz) {
            return ((sz + 1) / 2) >= n;
        }
        count += ((sz - e - 1) / 2);
        int zeros = 0;
        for (int i = s; i <= e; ++i) {
            if (flowerbed[i] == 0) {
                ++zeros;
            } else {
                count += ((zeros - 1) / 2);
                zeros = 0;
            }
        }
        return count >= n;
    }
};

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<int> flowerbed = stringToIntegerVector(s);
    cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}