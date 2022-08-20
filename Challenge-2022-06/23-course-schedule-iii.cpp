#include "../header.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) -> bool {return a[1] < b[1];});
        priority_queue<int> pq;
        int sum = 0;
        for (auto const& course: courses) {
            int t = course[0], d = course[1];
            pq.push(t);
            sum += t;
            if (sum > d) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};