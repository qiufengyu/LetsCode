#include "../header.h"

struct Item {
    int score;
    int index;
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<Item> v;
        for (int i = 0; i < n; i++) {
            v.push_back(Item{score[i], i});
        }
        sort(v.begin(), v.end(), [](const Item& a, const Item& b) -> bool {
            if (a.score < b.score) {
                return false;
            }
            return true;
        });
        vector<string> res(n);
        res[v[0].index] = "Gold Medal";
        if (n >= 2) {
            res[v[1].index] = "Silver Medal";
        }
        if (n >= 3) {
            res[v[2].index] = "Bronze Medal";
        }        
        for (int i = 3; i < n; i++) {
            res[v[i].index] = to_string(i+1);
        }
        return res;
    }
};