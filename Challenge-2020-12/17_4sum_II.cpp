#include "../header.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        unordered_map<int, int> mAB, mCD;
        for (int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            mAB[A[i]+B[j]]++;
            mCD[C[i]+D[j]]++;
          }
        }
        int res = 0;
        for (auto ab: mAB) {
          res += ab.second * mCD[-ab.first];
        }
        return res;
    }
};