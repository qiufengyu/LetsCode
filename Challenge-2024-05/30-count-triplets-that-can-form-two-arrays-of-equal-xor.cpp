#include "../header.h"

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<int> xors(n+1, 0);
        int x = 0;
        for (int i = 1; i <= n; i++) {
            x = x ^ arr[i-1];
            xors[i] = x;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int tmp = xors[j] ^ xors[i];
                if (tmp == 0) {
                    res += (j - i - 1);
                }
            }
        }
        return res;        
    }
};