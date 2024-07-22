#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[i] -= res[i][j];
            }
        }
        return res;
    }
};

int main() {
    vector<int> rowSum {4,12,10,1,0}, colSum{1,0,3,16,7};
    auto res = Solution().restoreMatrix(rowSum, colSum);
    print_vector<int>(res);
    return 0;
}