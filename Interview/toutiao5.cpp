//
// Created by Fengyu Qiu on 2018/8/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 10000

int main() {
    int N, M;
    cin>>N;
    cin>>M;
    pair<int, int> itv[MAX_N];
    int s = 0, t = 0;
    int ar[MAX_N*2];
    for(int i = 0; i<2*N; i++) {
        cin>>ar[i];
        // cout<<ar[i]<<endl;
    }
    for(int i = 0; i<2*N; i += 2) {
        itv[i/2].second = ar[i];
        itv[i/2].first = ar[i+1];
        /*
        if(itv[i/2].first<itv[i/2].second) {
            itv[i/2].first += M;
        }
         */
    }
    sort(itv, itv+N);
    int ans = 0, temp = 0;
    for(int i = 0; i<N; ++i) {
        if(temp <= itv[i].second) {
            ans++;
            temp = itv[i].first;
        }
    }
    printf("%d\n", ans);
    return 0;
}


