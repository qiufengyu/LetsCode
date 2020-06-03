//
// Created by Godfray on 2018/3/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i<nums.size()) {
            int start = i+1, end = nums.size() - 1;
            int a = nums[i];
            while(start < end) {
                int b = nums[start], c = nums[end];
                int sum = a + b + c;
                if (sum == 0) {
                    ret.push_back({a, b, c});
                    do {
                        start++;
                    } while( (start < end) && nums[start] == b);
                    do {
                        end--;
                    } while( (start < end) && nums[end] == c);
                }
                else if (sum > 0) {
                    do {
                        end--;
                    } while( (start<end) && (nums[end] == c));
                }
                else {
                    do {
                        start++;
                    } while( start<end && nums[start] == b);
                }
            }
            do {
                i++;
            } while( i < nums.size() && nums[i] == a);
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

    vector<vector<int>> r = Solution().threeSum(v);
    for(auto inner: r) {
        for(auto i: inner) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

