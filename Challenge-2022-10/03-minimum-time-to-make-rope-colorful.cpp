#include "../header.h"

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 1, res = 0, n = neededTime.size();
        for (int i = 1; i < n; ++i) {
            if (colors[i] == colors[i-1]) {
                ++count;
            } else {
                if (count > 1) {
                    int mx = 0, s = 0;
                    for (int j = i - 1; j >= i - count; --j) {
                        s += neededTime[j];
                        mx = max(mx, neededTime[j]);
                        cout << i << " ---- " << count << endl;
                        cout << s << ", " << mx << endl;
                    }
                    res += (s - mx);
                }
                count = 1;
            }
        }
        if (count > 1) {
            int mx = 0, s = 0;
            for (int j = n - 1; j >= n - count; --j) {
                s += neededTime[j];
                mx = max(mx, neededTime[j]);
                cout << "last" << " ---- " << count << endl;
                cout << s << ", " << mx << endl;
            }
            res += (s - mx);
        }        
        return res;
    }
};

int main() {
    string colors;
    cin >> colors;
    string s;
    cin >> s;
    vector<int> neededTime = stringToIntegerVector(s);
    cout << Solution().minCost(colors, neededTime);
    return 0;
}