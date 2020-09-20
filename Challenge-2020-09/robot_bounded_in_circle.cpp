#include "../header.h"

const vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        for (char i: instructions) {
            if (i == 'G') {
                x += directions[dir][0];
                y += directions[dir][1];
            } else if (i == 'R') {
                dir = (dir + 1) % 4;
            } else {
                dir = (dir + 3) % 4;
            }
        }
        return (x == 0 && y == 0) || (dir != 0);
    }
};

int main() {
    string inst;
    cin >> inst;
    cout << Solution().isRobotBounded(inst) << endl;
    return 0;
}

