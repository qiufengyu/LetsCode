//
// Created by Fengyu Qiu on 2018/6/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0;
        int i = 0, sz = flowerbed.size();
        // leading 0's
        for(; i < sz; ++i) {
            if(flowerbed[i]) break;
        }
        if(i == sz) {
            i++;
        }
        res += i / 2;
        // last 0's
        int j = sz - 1;
        for(; j > i; --j) {
            if(flowerbed[j]) break;
        }
        res += (sz - j - 1) / 2;
        for(; i < j; ++i) {
            if(flowerbed[i]) continue;
            else {
                int cnt = 1, k = i+1;
                while(!flowerbed[k++]) {
                    cnt++;
                }
                i = k-1;
                res += (cnt - 1) / 2;
            }
        }
        // cout<<res<<endl;
        return res >= n;
    }
};

int main() {
    vector<int> flower = {1,0};
    auto res = Solution().canPlaceFlowers(flower, 2);
    cout<<res<<endl;
    return 0;
}
