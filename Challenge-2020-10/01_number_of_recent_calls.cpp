#include "../header.h"

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (!q.empty() && q.front() + 3000 < t) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};