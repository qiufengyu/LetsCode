#include "../header.h"

class Solution {    
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(n), size(n, 1);
        iota(parent.begin(), parent.end(), 0);
        unordered_map<int, vector<int>> primeTable;
        for (int i = 0; i < n; i++) {
            prime(primeTable, nums[i], i);
        }
        for (auto const& p: primeTable) {
            vector<int> lst = p.second;
            for (int i = 1; i < lst.size(); i++) {
                u(parent, size, lst[0], lst[i]);
            }
        }
        // check all parents
        int p = f(parent, parent[0]);
        for (int i = 1; i < n; i++) {
            if (f(parent, parent[i]) != p) {
                return false;
            }
        }
        return true;
    }

    void prime(unordered_map<int, vector<int>>& table, int number, int index) {
        if (number % 2 == 0) {
            table[2].push_back(index);
        }
        while (number % 2 == 0) {
            number /= 2;
        }
        for (int i = 3; i <= sqrt(number); i += 2) {
            if (number % i == 0) {
                table[i].push_back(index);
            }
            while (number % i == 0) {
                number /= i;
            }
        }
        if (number > 1) {
            table[number].push_back(index);
        }
    }

    void u(vector<int>& parent, vector<int>& size, int x, int y) {
        int fx = f(parent, x), fy = f(parent, y);
        if (fx == fy) {
            return;
        }
        if (size[fx] < size[fy]) {
            parent[fx] = fy;
            size[fy] += size[fx];
        } else {
            parent[fy] = fx;
            size[fx] += size[fy];
        }
    }

    int f(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        int p = f(parent, parent[x]);
        parent[x] = p;
        return p;
    }
};