#include "../header.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int sz = arr.size();
        vector<bool> visited(sz, false);
        bool res = false;
        reach(arr, visited, start, sz, res);
        return res;
    }

    void reach(vector<int>& arr, vector<bool>& visited, int index, const int sz, bool& res) {
        if (!visited[index]) {
            visited[index] = true;
            if (arr[index] == 0) {
                res = true;
                return;
            }
            if (index + arr[index] < sz) {
                reach(arr, visited, index + arr[index], sz, res);
            }
            if (index - arr[index] >= 0) {
                reach(arr, visited, index - arr[index], sz, res);
            }            
        }
    }
};