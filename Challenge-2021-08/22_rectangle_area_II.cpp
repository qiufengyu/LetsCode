#include "../header.h"
#include <list>

const int M = 1e9 + 7;

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<int> xs;
        int sumArea = 0;
        for (auto const& rectangle: rectangles) {
            xs.push_back(rectangle[0]);
            xs.push_back(rectangle[2]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        for (int i = xs.size() - 2; i >= 0; --i) {
            list<pair<int, int>> l;
            for (auto const& rectangle: rectangles) {
                if (rectangle[0] <= xs[i] && rectangle[2] >= xs[i+1]) {
                    addRange(l, rectangle[1], rectangle[3]);
                }
            }
            long distY = 0;
            for (auto const& item: l) {
                distY += item.second - item.first;
            }
            sumArea = (sumArea + (xs[i+1] - xs[i]) * distY) % M;
        }
        return sumArea;
    }

    void addRange(list<pair<int, int>>& l, int left, int right) {
        auto it = l.begin();
        while (it != l.end() && it->second < left) {
            ++it;
        }
        if (it == l.end() || it->first > right) {
            l.insert(it, {left, right});
        } else {
            it->first = min(it->first, left);
            it->second = max(it->second, right);
            auto beforeIt = it;
            it++;
            while (it != l.end() && beforeIt->second >= it->first) {
                beforeIt->second = max(it->second, beforeIt->second);
                it = l.erase(it);
            }
        }
    }
};