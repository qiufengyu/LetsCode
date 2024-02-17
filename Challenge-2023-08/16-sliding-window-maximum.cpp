#include "../header.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		priority_queue<pair<int, int>> pq;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			pq.push({nums[i], i});
			if (i >= k - 1) {
				while (i - pq.top().second >= k) {
					pq.pop();
				}
				res.push_back(pq.top().first);
			}
		}
		return res;        
    }
};