//
// Created by Fengyu Qiu on 2018/6/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval a, Interval b) {
    return (a.end < b.end);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int sz = intervals.size();
        if(sz == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int noneOverlap = 0;
        int endValue = intervals[0].start - 1;
        for(auto x: intervals) {
            if(endValue <= x.start ) {
                noneOverlap++;
                endValue = x.end;
            }
        }
        return (sz - noneOverlap);

    }
};


int main() {
    Interval i1(1,2);
    Interval i2(2,4);
    Interval i3(3,5);
    Interval i4(1,3);
    vector<Interval> v;
    v.push_back(i1);
    v.push_back(i2);
    v.push_back(i3);
    v.push_back(i4);
    int res = Solution().eraseOverlapIntervals(v);
    cout<<res<<endl;
    return 0;
}
