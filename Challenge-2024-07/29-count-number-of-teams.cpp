#include "../header.h"

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> leftSmaller(n), leftLarger(n), rightSmaller(n), rightLarger(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    leftSmaller[i]++;
                } else {
                    leftLarger[i]++;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (rating[j] < rating[i]) {
                    rightSmaller[i]++;
                } else {
                    rightLarger[i]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += leftSmaller[i] * rightLarger[i];
            res += leftLarger[i] * rightSmaller[i];
        }
        return res;
    }
};