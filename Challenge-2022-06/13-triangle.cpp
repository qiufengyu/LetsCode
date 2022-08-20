#include "../header.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> sum(n, vector<int>(n, 0));
        sum[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            sum[i][0] = triangle[i][0] + sum[i-1][0];
            for (int j = 1; j < i; ++j) {
                sum[i][j] = min(sum[i-1][j-1], sum[i-1][j]) + triangle[i][j];
            }
            sum[i][i] = sum[i-1][i-1] +  triangle[i][i];
        }
        // print_vector<int>(sum);
        return *min_element(sum[n-1].begin(), sum[n-1].end());
    }
};

int main() {
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = Solution().minimumTotal(triangle);
    cout << res << endl;
    return 0;
}