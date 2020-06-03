//
// Created by Godfray on 2018/3/27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int sum;
        int i = 0;
        int sz = nums.size() - 1;
        while(i < sz-2) {
            if(i>0 && nums[i] == nums[i-1]) {
                i++;
                continue; // 重复数字不考虑
            }
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break; // 往后也不可能了，提前结束程序
            if(nums[i] + nums[sz] + nums[sz-1] + nums[sz-2] < target) {i++; continue;} // 当前的 i 不合适！下一轮
            for(int j = i+1; j<sz-1; ++j) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[sz] + nums[sz-1] < target) continue;
                int left = j + 1, right = sz;
                while(left < right) {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else {
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        do {
                            left++;
                        } while(left < right && nums[left] == nums[left-1]);
                        do {
                            right--;
                        } while(left < right && nums[right] == nums[right+1]);
                    }
                }
            }
            i++;
        }
        return ret;
    }
};


int main() {
    vector<int> v;
    int i = 0;
    cin >> i;
    while(i != -99) {
        v.push_back(i);
        cin>>i;
    }
    for(auto x: v) {
        cout<<x<<" ";
    }
    cout<<endl;

    vector<vector<int>> r = Solution().fourSum(v, 1);
    for(auto inner: r) {
        for(auto i: inner) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

