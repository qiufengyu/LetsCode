#include "../header.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = rooms.size();
        queue<int> q;
        vector<int> r0 = rooms[0];
        unordered_set<int> visited;
        visited.insert(0);
        q.push(0);
        int count = 0;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            count++;            
            vector<int> v = rooms[f];
            for (int i: v) {
                if (visited.count(i) == 0) {
                    visited.insert(i);
                    q.push(i);
                }
            }
        }
        return count == sz;
    }
};
