#include <iterator>
#include "header.h"

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> r;
        N = N % 14;
        if ( N = 0 ) {
            N = 14;
        }
        r.assign(cells.begin(), cells.end());
        for (int i = 0; i < N ; i++) {
            for (int j = 1; j < 7; j++) {
                if (cells[j-1] == cells[j+1]) {
                    r[j] = 1;
                } else {
                    r[j] = 0;
                }
            }
            r[0] = 0; r[7] = 0;
            cells.assign(r.begin(), r.end());
            cout << i + 1 << ":\t";
            for (auto x: r) {
                cout << x << " ";
            }
            cout << endl;
        }
        r[0] = 0; r[7] = 0;
        return r;        
    }
};

int main() {
    vector<int> cells {1,0,0,1,0,0,0,1};
    int N = 826;
    vector<int> r = Solution().prisonAfterNDays(cells, N);
    for (auto x: r) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
