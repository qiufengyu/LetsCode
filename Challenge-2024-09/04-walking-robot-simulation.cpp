#include "../header.h"

enum Direction {
    N, S, W, E
};

struct Point
{
  int x;
  int y;

  Point() {}
  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
  
  bool operator==(const Point& otherPoint) const
  {
    if (this->x == otherPoint.x && this->y == otherPoint.y) return true;
    else return false;
  }

  struct HashFunction
  {
    size_t operator()(const Point& point) const
    {
      size_t xHash = std::hash<int>()(point.x);
      size_t yHash = std::hash<int>()(point.y) << 1;
      return xHash ^ yHash;
    }
  };
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int res = 0, x = 0, y = 0;
        unordered_set<Point, Point::HashFunction> st;
        for (auto const& ob: obstacles) {
            st.insert(Point(ob[0], ob[1]));
        }
        Direction d = N;
        int n = commands.size();
        for (int i = 0; i < n; i++) {
            int cmd = commands[i];
            if (cmd > 0) {
                switch (d) {
                    case N: {
                        while (cmd > 0) {
                            if (st.count(Point{x, y + 1}) == 0) {
                                y++;
                            } else {
                                break;
                            }
                            cmd--;
                        }
                    } break;
                    case E: {
                        while (cmd > 0) {
                            if (st.count(Point{x + 1, y}) == 0) {
                                x++;
                            } else {
                                break;
                            }
                            cmd--;
                        }
                    } break;
                    case S:{
                        while (cmd > 0) {
                            if (st.count(Point{x, y - 1}) == 0) {
                                y--;
                            } else {
                                break;
                            }
                            cmd--;
                        }
                    } break;
                    case W:{
                        while (cmd > 0) {
                            if (st.count(Point{x - 1, y}) == 0) {
                                x--;
                            } else {
                                break;
                            }
                            cmd--;
                        }
                    } break;
                    default:
                        break;
                }
            } else if (cmd == -1) {
                switch (d) {
                    case N:
                        d = E;
                        break;
                    case E:
                        d = S;
                        break;
                    case S:
                        d = W;
                        break;
                    case W:
                        d = N;
                        break;
                    default:
                        break;
                }
            } else {
                switch (d) {
                    case N:
                        d = W;
                        break;
                    case E:
                        d = N;
                        break;
                    case S:
                        d = E;
                        break;
                    case W:
                        d = S;
                        break;
                    default:
                        break;
                }
            }
            res = max(x * x + y * y, res);
        }
        return res;
    }
};

int main() {
    vector<int> cmds {4, -1, 3};
    vector<vector<int>> obs {};
    cout << Solution().robotSim(cmds, obs) << endl;
    return 0;
}