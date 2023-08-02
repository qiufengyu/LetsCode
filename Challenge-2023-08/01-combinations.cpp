#include "../header.h"

class Solution {
	void helper(vector<vector<int>>& res, vector<int>& array, int start, int length, int n, int k) {
		if (length == k) {
			res.push_back(array);
			return;
		}
		for (int i = start; i <= n; i++) {
			array.push_back(i);
			helper(res, array, start+1, length+1, n, k);
			array.pop_back();
		}
	}
public:
    vector<vector<int>> combine(int n, int k) {
		vector<int> array;
		vector<vector<int>> res;
		helper(res, array, 1, 0, n, k);
        return res;
    }
};