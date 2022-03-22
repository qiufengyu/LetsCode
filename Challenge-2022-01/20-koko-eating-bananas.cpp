#include "../header.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mn = 1, mx = *max_element(piles.begin(), piles.end());
        int m = (mn + mx) / 2, hrs = 0;
        while (mn < mx) {
            m = (mn + mx) / 2;
            hrs = 0;
            for (int const& pile: piles) {
                hrs += pile / m + 1 * int((pile % m) != 0);
            }
            if (hrs > h) {
                mn = m + 1;
            } else {
                mx = m;
            }
            // cout << mn << " " << m << " " << mx << ", " << hrs << endl;
        }
        return mn;
    }
};

int main() {
    string s;
    int h;
    cin >> s;
    cin >> h;
    vector<int> piles = stringToIntegerVector(s);
    cout << Solution().minEatingSpeed(piles, h) << endl;
    return 0;
}