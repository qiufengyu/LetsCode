#include "../header.h"

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < arr.size(); ++i) {
            m[arr[i]].push_back(i);
        }
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int j = 0; j < sz; ++j) {
                int f = q.front();
                q.pop();
                if (f == n - 1) {
                    return res;
                }
                if (f - 1 >= 0 && !visited[f - 1]) {
                    visited[f - 1] = true;
                    q.push(f - 1);
                }
                if (f + 1 < n && !visited[f + 1]) {
                    visited[f + 1] = true;
                    q.push(f + 1);
                }
                if (m.count(arr[f])) {
                    for (int const& i: m[arr[f]]) {
                        if (!visited[i]) {
                            visited[i] = true;
                            q.push(i);
                        }
                    }
                    // without removing it, may cause TLE
                    m.erase(arr[f]);
                }
            }
            ++res;
        }
        return -1;
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> v = stringToIntegerVector(s);
    cout << Solution().minJumps(v) << endl;
    return 0;
}