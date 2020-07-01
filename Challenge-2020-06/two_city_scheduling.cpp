#include "header.h"

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int count1 = 0;
        int count2 = 0;
        int count0 = 0;
        vector<int> equal;
        priority_queue<int, vector<int>, greater<int>> to2;
        priority_queue<int, vector<int>, greater<int>> to1;
        int res = 0;
        for(auto &v: costs) {
            if (v[0] < v[1]) {
                res += v[0];
                cout << "add " << v[0] << endl;
                to2.push(v[1]-v[0]);
                cout << "to2 " << v[1]-v[0] << endl;
                count1++;
            } else if (v[0] > v[1]) {
                res += v[1];
                to1.push(v[0]-v[1]);
                count2++;
                cout << "add " << v[1] << endl;
                cout << "to1 " << v[0]-v[1] << endl;
            } else {
                count0++;
                res += v[0];
                cout << "add " << v[0] << " equal" << endl;
            }
        }
        int diff = (abs(count1 - count2) - count0) / 2;  
        cout << "diff = " << diff << endl;
        if (count1 < count2) {
            while (diff > 0) {
                res += to1.top();
                cout << "2 -> 1 offset " << to1.top() << endl;
                to1.pop();
                diff--;
            }
        } else {
            while(diff > 0) {
                res += to2.top();
                cout << "1 -> 2 offset " << to2.top() << endl;
                to2.pop();
                diff--;
            }
        }        
        return res;      
    }
};

int main() {
    vector<vector<int>> v {{518,518},{71,971},{121,862},{967,607},{138,754},{513,337},{499,873},{337,387},{647,917},{76,417}};
    cout << Solution().twoCitySchedCost(v) << endl;
    return 0;
}