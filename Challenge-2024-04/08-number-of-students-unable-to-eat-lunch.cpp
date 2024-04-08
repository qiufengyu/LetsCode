#include "../header.h"

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0, n = students.size();
        for (int i = 0; i < n; i++) {
            if (students[i] == 0) {
                count0++;
            } else {
                count1++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (sandwiches[i] == 0) {
                if (count0 > 0) {
                    count0--;
                } else {
                    return n - i;
                }
            } else {
                if (count1 > 0) {
                    count1--;
                } else {
                    return n - i;
                }
            }
        }
        return 0;

    }
};