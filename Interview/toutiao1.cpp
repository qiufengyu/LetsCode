//
// Created by Fengyu Qiu on 2018/8/12.
//

#include <iostream>
#include <string>
using namespace std;
#define MAX_N 1001

bool seats[MAX_N][MAX_N];
int M = 0, N = 0;
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int maxPeople = 0;

void dfs(int x, int y) {
    seats[x][y] = false;
    for(int i = 0; i<8; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx >= 0 && ty >= 0 && tx < M && ty < N && seats[tx][ty]) {
            dfs(tx, ty);
            maxPeople++;
        }
    }
}

int main() {
    scanf("%d,%d", &M, &N);
    for(int i = 0; i<M; ++i) {
        string temp;
        getline(cin, temp);
        for(int j = 0; j<temp.length(); j += 2) {
            seats[i][j/2] = (temp[j]=='1');
        }
    }
    // dfs
    int groups = 0;
    int maxPeopleAns = 0;
    for(int i = 0; i<M; ++i) {
        for(int j = 0; j<N; ++j) {
            if(seats[i][j]) {
                maxPeople = 1;
                dfs(i, j);
                groups++;
            }
            maxPeopleAns = (maxPeople > maxPeopleAns)? maxPeople : maxPeopleAns;
        }
    }
    printf("%d,%d\n", groups, maxPeopleAns);
    return 0;
}


