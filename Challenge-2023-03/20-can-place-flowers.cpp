#include "../header.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0) {
                return n <= 1;
            }
            return n == 0;
        }
        int pos = 0;
        while (pos < flowerbed.size() && flowerbed[pos] == 0) {            
            ++pos;
        }
        // special case for all 0's   
        if (pos == flowerbed.size()) {
            return (pos + 1) / 2 >= n;
        }
        n -= (pos / 2);
        if (n <= 0) {
            return true;
        }
        int lpos = flowerbed.size() - 1;
        while (lpos >= pos && flowerbed[lpos] == 0) {
            lpos--;
        }
        n -= ((flowerbed.size() - lpos - 1) / 2);
        if (n <= 0) {
            return true;
        }
        // in the middle, i >= 1 && i <= flowerbed size - 2
        for (int i = pos + 1; i < lpos; ++i) {
            if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                --n;
                if (n <= 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> flowerbed {1,0,0,0,0,1};
    int n = 2;
    cout << Solution().canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}