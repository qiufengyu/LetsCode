#include "header.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m;
        m[0] = -1;
        int count = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count--;
            }
            if (m.find(count) == m.end()) {
                m[count] = i;
            } else {
                ans = max(ans, i - m[count]);
            }
        }
        return ans;
        // int sz = nums.size();
        // vector<vector<int>> res(sz, vector<int>(sz, 0));
        // for (int i = 0; i<sz; i++) {
        //     res[i][i] = nums[i];
        // }
        // int ans = 0;
        // for (int i = 0; i < sz; i++) {
        //     for(int j = i + 1; j < sz; j++) {
        //         res[i][j] = res[i][j-1] + nums[j];
        //         if ((j - i + 1) == 2 * res[i][j]) {
        //             if (ans < 2 * res[i][j]) {
        //                 ans = 2 * res[i][j];
        //             }
        //         }
        //     }
        // }
        // return ans;
    }
};

int main() {
    vector<int> v {1,1,0,0,0,1,0,1};
    cout << Solution().findMaxLength(v) << endl;
}