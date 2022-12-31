#include "../header.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> us;
        us.emplace(0);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int r = q.front();
                q.pop();
                for (auto const& k: rooms[r]) {
                    if (us.find(k) == us.end()) {
                        us.emplace(k);
                        q.push(k);
                    }
                }
                --sz;
            }
        }
        return n == us.size();
    }
};