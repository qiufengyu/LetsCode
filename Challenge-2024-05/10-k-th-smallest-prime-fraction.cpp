#include "../header.h"

struct Item {
    int i1;
    int i2;
    double val;
    Item(int i, int j, double d): i1{i}, i2{j}, val{d} {}
    bool operator<(const Item& other) const {
        return val < other.val;
    }    
    bool operator>(const Item& other) const {
        return val >= other.val;
    }
    bool operator==(const Item& other) const {
        return i1 == other.i1 && i2 == other.i2;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<Item, vector<Item>, greater<Item>> pq;
        Item item{0, n-1, (double)arr[0]/arr[n-1]};
        pq.push(item);
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][n-1] = true;
        vector<int> res{arr[0], arr[n-1]};
        while (k) {
            Item tp = pq.top();
            pq.pop();
            int i = tp.i1, j = tp.i2;
            res[0] = arr[i];
            res[1] = arr[j];
            if (i + 1 < j && (!visited[i+1][j])) {
                pq.push(Item{i+1, j, double(arr[i+1])/arr[j]});
                visited[i+1][j] = true;
            }
            if (i < j - 1 && (!visited[i][j-1])) {
                pq.push(Item{i, j-1, double(arr[i])/arr[j-1]});
                visited[i][j-1] = true;
            }
            k--;
        }
        return res;        
    }
};