#include "../header.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int sz = arr.size();
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int qz = q.size();
            for (int i = 0; i < qz; ++i) {
                int t = q.front();
                q.pop();
                if (arr[t] == 0) {
                    return true;
                }
                int l = t - arr[t], r = t + arr[t];
                arr[t] = -arr[t];
                if (l >= 0 && arr[l] >= 0) {
                    q.push(l);
                }
                if (r < sz && arr[r] >= 0) {
                    q.push(r);
                }
            }
        }
        return false;
    }
};

int main() {
    string s;
    int start;
    cin >> s;
    cin >> start;
    vector<int> arr = stringToIntegerVector(s);
    cout << Solution().canReach(arr, start) << endl;
    return 0;
}