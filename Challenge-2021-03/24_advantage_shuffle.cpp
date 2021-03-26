#include "../header.h"

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size(), 0);
        sort(A.begin(), A.end());
        for (int i = 0; i < B.size(); ++i) {
            auto it = upper_bound(A.begin(), A.end(), B[i]);
            if (it == A.end()) {
                it = A.begin();
            }
            res[i] = *it;
            A.erase(it);
        }
        return res;
    }
};