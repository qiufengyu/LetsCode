#include "../header.h"

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        priority_queue<int, vector<int>, greater<int>> pq(deck.begin(), deck.end());
        vector<int> res(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        vector<int> idx(n, 0);
        for (int i = 0; i < n; i++) {
            int x = q.front();
            q.pop();
            idx[i] = x;
            x = q.front();
            q.pop();
            q.push(x);
        }
        for (int i = 0; i < n; i++) {
            res[idx[i]] = pq.top();
            pq.pop();
        }
        return res;
    }
};