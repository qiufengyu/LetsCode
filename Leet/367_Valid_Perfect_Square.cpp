//
// Created by Fengyu Qiu on 2018/7/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        int end = num;
        if(num == 1) {
            return true;
        }
        int mid = 0;
        while(start < end) {
            if(mid == (start + end) / 2) {
                break;
            }
            else {
                mid = (start + end) / 2;
            }
            if(mid * mid == num) {
                return true;
            }
            if(num / mid > mid) {
                start = mid;
            }
            else if(num / mid < mid) {
                end = mid;
            }
        }
        return mid * mid == num;
        /*
        int mid = start + (end - start) / 2;
        while(start < end) {
            mid = start + (end - start) / 2;
            if(num / mid > mid) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return start * start == num;
         */
    }
};

int main() {
    vector<int> v = {7,6,8,0,4,2,1,5};
    sort(v.begin(), v.end());
    auto res = Solution().isPerfectSquare(1);
    cout<<res<<endl;
    return 0;
}
