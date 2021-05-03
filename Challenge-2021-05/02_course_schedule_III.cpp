#include "../header.h"

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) -> bool { return a[1] < b[1]; });
        priority_queue<int, vector<int>, less<int>> pq;
        int day = 0;
        for (int i = 0; i < courses.size(); ++i) {
          if (day + courses[i][0] <= courses[i][1]) {
            pq.push(courses[i][0]);
            day += courses[i][0];
          } else {
            pq.push(courses[i][0]);
            day += courses[i][0];
            int maxDuration = pq.top();
            day -= maxDuration;
            pq.pop();
          }
        }
        return pq.size();
    }
};