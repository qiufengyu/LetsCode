#include "../header.h"

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> s;
        unordered_map<char, pair<int, int>> m;
        m['N'] = {0, 1};
        m['S'] = {0, -1};
        m['E'] = {1, 0};
        m['W'] = {-1, 0};
        int x = 0, y = 0;
        stringstream ss;
        ss << x << "#" << y;
        cout << ss.str() << endl;
        s.insert(ss.str());
        for (int i = 0; i < path.size(); i++) {
            ss = stringstream();
            x += m[path[i]].first;
            y += m[path[i]].second;
            ss << x << "#" << y;
            cout << ss.str() << endl;
            if (s.count(ss.str())) {
                return true;
            } else {
                s.insert(ss.str());
            }
        }
        return false;        
    }
};

int main() {
    string s = "NESWW";
    cout << Solution().isPathCrossing(s) << endl;
    return 0;
}