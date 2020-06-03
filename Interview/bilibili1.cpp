//
// Created by Fengyu Qiu on 2018/10/18.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> weapons;
    int n;
    cin>>n;
    int w;
    for(int i = 0; i<n; ++i) {
        cin>>w;
        weapons.push_back(w);
    }
    vector<vector<bool> >dp;
    for(int i = 0; i<n; ++i) {
        vector<bool> temp;
        for(int j = 0; j<n; ++j) {
            temp.push_back(false);
        }
        dp.push_back(temp);
    }
    for(int i = 0; i<n-2; ++i) {
        for(int j = i+1; j<n; ++j) {
            // 计算 dp[i][j]
            if(dp[i][j-1]) {
                dp[i][j] = true;
                continue;
            }
            // 否则，查找 i 到 (j-1) 中的两个数，加上这个新的数，即 weapon[j] 能够构成三角形
            int x1 = weapons[j];
            for(int k = i; k<j-1; ++k) {
                int x2 = weapons[k];
                for(int l = i+1; l<j; ++l) {
                    int x3 = weapons[l];
                    int y1 = min(x1, min(x2, x3));
                    int y2 = max(x1, max(x2, x3));
                    int y3 = x1+x2+x3-y1-y2;
                    if(y1 + y3 > y2)
                        dp[i][j] = true;
                }
            }
        }
    }
    int m;
    cin>>m;
    int a, b;
    int res = 0;
    for(int t = 0; t<m; ++t) {
        cin>>a>>b;
        if(dp[a-1][b-1])
            res++;
    }

    cout<<res<<endl;
    return 0;
}