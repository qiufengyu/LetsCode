#include "header.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> un;
        un.push_back(1);
        int f2 = 0, f3 = 0, f5 = 0;
        int v2 = un[f2] * 2, v3 = un[f3] * 3, v5 = un[f5] * 5;
        for (int i = 1; i < n; i++) {
            v2 = un[f2] * 2;
            v3 = un[f3] * 3;
            v5 = un[f5] * 5;
            if (v2 <= v3 && v2 <= v5) {
                f2++;
                un.push_back(v2);
                f3 += (int) v2 == v3;
                f5 += (int) v2 == v5;
            } else if (v3 <= v2 && v3 <= v5) {                
                f3++;
                un.push_back(v3);
                f2 += (int) v3 == v2;
                f5 += (int) v3 == v5;
            } else if (v5 <= v2 && v5 <= v3) {
                f5++;
                un.push_back(v5);
                f2 += (int) v5 == v2;
                f3 += (int) v5 == v3;
            }
        }
        return un[n-1];
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().nthUglyNumber(n) << endl;
    return 0;
}