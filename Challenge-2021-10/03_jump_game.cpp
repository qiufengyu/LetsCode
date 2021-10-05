#include "../header.h"

class Solution {
public:
    bool canJunp(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) {
                break;
            }
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }

    bool canJump2(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        return helper(nums, 0, visited, n);        
    }

    bool helper(vector<int>& nums, int index, vector<bool>& visited, const int n) {
        if (index == n - 1) {
            return true;
        }
        for (int i = 1; i <= nums[index]; ++i) {
            int nIndex = index + i;
            if (nIndex < n && (!visited[nIndex])) {
                visited[nIndex] = true;
                if (helper(nums, nIndex, visited, n)) {
                    return true;
                }
                visited[nIndex] = false;
            }            
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    cout << Solution().canJump(nums) << endl;
    return 0;
}