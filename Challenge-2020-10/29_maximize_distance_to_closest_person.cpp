#include "../header.h"

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0;
        while(i < seats.size()) {
            if (seats[i] == 1) {
                break;
            }
            i++;
        }
        int ans = i;
        int middleZeros = 0;
        while(i < seats.size()) {
            if (seats[i] == 0) {
                middleZeros++;
            } else {
                ans = max(ans, (middleZeros + 1) / 2);
                middleZeros = 0;
            }
            i++;
        }
        return max(ans, middleZeros);
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> seats = stringToIntegerVector(s);
    cout << Solution().maxDistToClosest(seats) << endl;
    return 0;
}