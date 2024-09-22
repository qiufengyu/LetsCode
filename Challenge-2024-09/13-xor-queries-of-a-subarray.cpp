#include "../header.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        size_t n = arr.size();
        vector<int> preXor(n, 0);
        preXor[0] = arr[0];
        for (int i = 1; i < n; i++) {
            preXor[i] = preXor[i - 1] ^ arr[i];
        }
        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            if (x == 0) {
                res[i] = preXor[y];
            } else {
                res[i] = preXor[y] ^ preXor[x-1];
            }
        }
        return res;
    }
};