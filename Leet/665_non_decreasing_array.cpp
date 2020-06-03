//
// Created by Fengyu Qiu on 2018/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz = nums.size();
        bool flag = true;
        for(int i = 0; i<sz-1; ++i) {
            if(nums[i] <= nums[i+1]) continue;
            else { // nums[i+1] < nums[i]
                if(flag) {
                    flag = false;
                    if(i > 0 && nums[i+1] < nums[i-1]) {
                        nums[i+1] = nums[i];
                    }
                    else {
                        nums[i] = nums[i+1];
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> v = {4,2,1};
    auto res = Solution().checkPossibility(v);
    cout<<res<<endl;
    return 0;
}
