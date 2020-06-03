//
// Created by Fengyu Qiu on 2018/6/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return (a.second < b.second);
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int overlap = 1;
        int endValue = points[0].second;
        for(auto x: points) {
            if(endValue < x.first) {
                overlap++;
                endValue = x.second;
            }
        }
        return overlap;
    }
};


int main() {

    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 2));
    v.push_back(make_pair(3, 4));
    v.push_back(make_pair(5, 6));
    v.push_back(make_pair(7, 8));
    int res = Solution().findMinArrowShots(v);
    cout<<res<<endl;
    return 0;
}
