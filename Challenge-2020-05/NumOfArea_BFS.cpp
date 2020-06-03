//
// Created by Fengyu Qiu on 2018/8/11.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int W = 10;
const int N = 5;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int compress(int *x1, int *x2, int W) {
    vector<int> xs;
    for(int i = 0; i < N; ++i) {
        for(int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if(tx1 >= 1 && tx1 <= W) xs.push_back(tx1);
            if(tx2 >= 1 && tx2 <= W) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for(int i = 0; i < N; ++i) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    for(int i = 0; i<N; ++i) {
        cout<<x1[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i<N; ++i) {
        cout<<x2[i]<<" ";
    }
    cout<<endl;
    cout<<xs.size()<<endl;
    return xs.size();
}

int main() {
    int x1[5] = {1,1,4,9,10};
    int x2[5] = {6,10,4,9,10};
    int y1[5] = {4,8,1,1,6};
    int y2[5] = {4,8,10,5,10};
    int w = compress(x1, x2, W);
    int h = compress(y1, y2, W);
    cout<<"w = "<<w << ", h = "<< h << endl;
    bool fld[N*6][N*6];
    memset(fld, 0, sizeof(fld));

    for(int i = 0; i<N; ++i) {
        for(int y = y1[i]; y<=y2[i]; y++) {
            for(int x = x1[i]; x<=x2[i]; x++) {
                fld[y][x] = true;
            }
        }
    }

    for(int i = 0; i<h; ++i) {
        for(int j = 0; j<w; ++j) {
            if(fld[i][j]) cout<<"X ";
            else cout<<"  ";
        }
        cout<<endl;
    }

    int ans = 0;
    for(int y = 0; y<h; ++y) {
        for(int x = 0; x<w; ++x) {
            if(fld[y][x]) continue;
            ans++;
            queue<pair<int, int>> que;
            que.push(make_pair(x, y));
            while(!que.empty()) {
                int sx = que.front().first;
                int sy = que.front().second;
                que.pop();
                for(int i = 0; i<4; ++i) {
                    int tx = sx + dx[i], ty = sy + dy[i];
                    if(tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
                    if(fld[ty][tx]) continue;
                    que.push(make_pair(tx, ty));
                    fld[ty][tx] = true;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}


