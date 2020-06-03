//
// Created by Fengyu Qiu on 2018/6/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first > b.first) {
        return true;
    }
    else if(a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return false;
    }
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), cmp);
        for(auto x: people) {
            res.insert(res.begin() + x.second, x);
        }
        return res;
    }
};


int main() {

    vector<pair<int, int> > v;
    v.push_back(make_pair(7, 0));
    v.push_back(make_pair(4, 4));
    v.push_back(make_pair(7, 1));
    v.push_back(make_pair(5, 0));
    v.push_back(make_pair(6, 1));
    v.push_back(make_pair(5, 2));

    vector<pair<int, int> > res = Solution().reconstructQueue(v);
    for(auto x: res) {
        cout<<"["<<x.first<<", "<<x.second<<"]\n";
    }
    return 0;
}
