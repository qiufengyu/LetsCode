#include "../header.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone: stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x < y) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> stones = stringToIntegerVector(s);
    cout << Solution().lastStoneWeight(stones) << endl;
    return 0;
}