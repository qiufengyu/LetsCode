#include <iostream>
using namespace std;

bool isBadVersion(int n) {
    return n >= 4;
}

int firstBadVersion(int n) {
    int s = 1;
    int e = n;
    int m = (s / 2 + e / 2) + ( s % 2 + e % 2) / 2;
    while (s < e ) {
        if (isBadVersion(m)) {
            e = m;
        }
        else {
            s = m + 1;
        }
        m = (s / 2 + e / 2) + ( s % 2 + e % 2) / 2;
    }
    if (isBadVersion(s)) {
        return s;
    }        
    return e;        
}

int main() {
    int n = 5;
    int r = firstBadVersion(n);
    cout << r << endl;
    return 0;
}