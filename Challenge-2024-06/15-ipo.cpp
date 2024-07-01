#include "../header.h"

typedef pair<int, int> PII;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<PII> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = capital[i];
            v[i].second = profits[i];
        }
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int idx = 0;
        while (k > 0) {
            while (idx < n && v[idx].first <= w) {
                pq.push(v[idx].second);
                idx++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            k--;
        }
        return w;
    }
};

int main() {
    int k = 2, w = 0;
    vector<int> profits{1,2,3}, capital{0, 1, 1};
    cout << Solution().findMaximizedCapital(k, w, profits, capital) << endl;
    return 0;
}