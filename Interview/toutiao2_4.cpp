//
// Created by Fengyu Qiu on 2018/8/25.
//

//
// Created by Fengyu Qiu on 2018/8/12.
//
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int a[1001]; // 原始序列
int dp[100010];

int main()
{
    int n, t, num = 0, cnt = 0;
    int i, j;
    map<int, int> m;
    scanf("%d %d",&n, &t);
    for(i=0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
        num = max(num, m[a[i]]);
    }
    for(i=0;i<100010;i++)
        dp[i]=1000000001;
    if(t<=n) {
        for(i=0;i<t;i++)
        {
            for(j=0;j<n;j++)
            {
                *upper_bound(dp,dp+100010,a[j])=a[j];
            }
        }
        printf("%d\n", lower_bound(dp, dp+100010,1000000001) - dp);

    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                *upper_bound(dp,dp+100010,a[j])=a[j];
            }
        }
        long long ans=lower_bound(dp,dp+100010,1000000001)-dp+num*(t-n);
        printf("%lld\n",ans);
    }

    return 0;
}


