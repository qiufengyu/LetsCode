#include "../header.h"

struct Item {
    double ratio;
    int index;
    Item(double r, int i): ratio{r}, index{i} {}
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<Item> v;
        for (int i = 0; i < n; i++) {
            v.push_back(Item{double(wage[i])/quality[i], i});
        }
        sort(v.begin(), v.end(), [](const Item& i1, const Item& i2) -> bool {
            return i1.ratio < i2.ratio;
        });
        priority_queue<int> pq;
        double maxRatio = v[0].ratio;
        int qualitySum = 0;
        for (int i = 0; i < k; i++) {
            pq.push(quality[v[i].index]);
            qualitySum += quality[v[i].index];
            maxRatio = max(maxRatio, v[i].ratio);
        }
        double res = maxRatio * qualitySum;
        for (int i = k; i < n; i++) {
            maxRatio = max(maxRatio, v[i].ratio);
            qualitySum -= pq.top();
            pq.pop();
            qualitySum += quality[v[i].index];
            pq.push(quality[v[i].index]);
            res = min(res, maxRatio * qualitySum);
        }
        return res;
    }
};