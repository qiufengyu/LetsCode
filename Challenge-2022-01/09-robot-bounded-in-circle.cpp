#include "../header.h"

enum DIRECTION { NORTH, SOUTH, WEST, EAST};

DIRECTION go(DIRECTION d, char c) {
    if (c == 'L') {
        switch (d) {
            case NORTH: return WEST;        
            case SOUTH: return EAST;
            case WEST: return SOUTH;
            case EAST: return NORTH;
        }
    } else {
        switch (d) {
            case NORTH: return EAST;        
            case SOUTH: return WEST;
            case WEST: return NORTH;
            case EAST: return SOUTH;
        }
    }
}

class Solution {
public:
    bool isRobotBounded(string instructions) {
        DIRECTION d = NORTH;
        int x = 0, y = 0;
        for (int i = 0; i < instructions.size(); ++i) {
            char instruction = instructions[i];
            if (instruction == 'G') {
                switch (d) {
                    case NORTH: {
                        y++;
                        break;
                    }
                    case SOUTH: {
                        y--;
                        break;
                    }
                    case WEST: {
                        x--;
                        break;
                    }
                    case EAST: {
                        x++;
                        break;
                    }
                }
            } else {
                d = go(d, instruction);
            }
        }
        if (x == 0 && y == 0) {
            return true;
        }
        return d != NORTH;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().isRobotBounded(s) << endl;
    return 0;
}