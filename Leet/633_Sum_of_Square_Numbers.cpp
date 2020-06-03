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
    bool judgeSquareSum(int c) {
        int i = (int)sqrt(c);
        int j = 0;
        while(j <= i) {
            int s = i * i + j * j;
            if(s == c) {
                return true;
            }
            if(s < c) {
                j++;
            }
            else {
                i--;
            }
        }
        return false;
    }
};

int main() {
    vector<int> v = {7,6,8,0,4,2,1,5};
    sort(v.begin(), v.end());
    auto res = Solution().judgeSquareSum(2);
    cout<<res<<endl;
    return 0;
}
