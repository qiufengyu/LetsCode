//
// Created by Godfray on 2018/3/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum;
        // if ret = 0, [1,1,1,1] and 1!!!
        int ret = nums[1]+nums[2]+nums[0];
        int i = 0;
        while(i<nums.size()-1) {
            int start = i + 1, end = nums.size() - 1;
            int a = nums[i];
            while(start < end) {
                int b = nums[start], c = nums[end];
                int sum = a + b + c;
                if (sum == target) {
                    return sum;
                }
                if (abs(sum - target) < abs(ret - target)) {
                    ret = sum;
                }
                sum > target ? (end--) : (start++);
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

    int r = Solution().threeSumClosest(v, 10);
    cout<<r<<endl;
    return 0;
}

