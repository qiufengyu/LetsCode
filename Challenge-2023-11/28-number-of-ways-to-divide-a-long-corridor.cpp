#include "../header.h"

class Solution {
public:
    int numberOfWays(string corridor) {
        long long res = 1LL;
        int idx = 0;
        while (idx < corridor.size() && corridor[idx] == 'P') {
            idx++;
        }
        // now idx points to first 'S' in corridor
        int seats = 0, plants = 0;
        while (idx < corridor.size()) {
            if (corridor[idx] == 'S') {
                seats++;
            } else {
                plants++;
            }
            if (seats >= 2 && corridor[idx] == 'S') {
                if (seats % 2 == 0) {
                    plants = 0;
                } else if (corridor[idx] == 'S'){
                    res = res * (plants + 1) % 1000000007;
                }
            }
            idx++;

        }
        if (seats == 0 || (seats % 2 == 1)) {
            return 0;
        }
        return (int)res;
    }
};

int main() {
    string c{"SSPPSPS"};
    cout << Solution().numberOfWays(c) << endl;
    return 0;
}