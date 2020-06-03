//
// Created by Fengyu Qiu on 2018/8/12.
//

#include <iostream>

using namespace std;
#define MAX_N 1000001

int a[MAX_N];

int find(int b) {
    int r = b;
    while(a[r] != r) {
        r = a[r];
    }
    int i = b, j;
    while(i != r) {
        j = a[i];
        a[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) {
        a[fy] = fx;
    }
}

int main()
{
    int n, sum = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        int x = -1;
        while( (cin>>x) && x != 0) {
            join(i, x);
        }
    }
    for(int i = 1; i<=n; ++i) {
        if(a[i] == i) sum++;
    }
    cout<<sum<<endl;
    return 0;
}


