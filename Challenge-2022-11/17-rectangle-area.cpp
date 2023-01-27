#include "../header.h"

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ax = ax2 - ax1, bx = bx2 - bx1, ay = ay2 - ay1, by = by2 - by1;
        int s1 = ax * ay, s2 = bx * by;
        int xmin = min(ax1, bx1), xmax = max(ax2, bx2), ox = 0;
        if (xmax - xmin >= ax + bx) {
            // not overlap
            ox = 0;
        } else if (xmax - xmin > max(ax, bx)) {
            ox = ax + bx - (xmax - xmin);
        } else {
            ox = min(ax, bx);
        }
        int ymin = min(ay1, by1), ymax = max(ay2, by2), oy = 0;
        if (ymax - ymin >= ay + by) {
            // not overlap
            oy = 0;
        } else if (ymax - ymin > max(ay, by)) {
            oy = ay + by - (ymax - ymin);
        } else {
            oy = min(ay, by);
        }
        return s1 + s2 - ox * oy;
    }
};