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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int sz = numbers.size();
        int i = 0, j = sz-1;
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if(sum == target) {
                res[0] = i+1;
                res[1] = j+1;
                return res;
            }
            if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }
    }
};

int main() {
    vector<int> v = {7,6,8,0,4,2,1,5};
    sort(v.begin(), v.end());
    auto res = Solution().twoSum(v, 9);
    return 0;
}
