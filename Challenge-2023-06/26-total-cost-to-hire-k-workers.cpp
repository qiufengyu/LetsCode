#include "../header.h"

struct Item {
	int cost;
	int index;
	Item(int c, int i): cost{c}, index{i} {}
};

struct Compare {
	// sometimes, the top element in is not the one with least index if costs are same
	// so need to compare the index as the secondary condition
	bool operator()(Item i1, Item i2) {
		if (i1.cost > i2.cost) {
			return true;
		} else if (i1.cost < i2.cost) {
			return false;
		} else return i1.index > i2.index;
	}
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res = 0LL;
		int n = costs.size(), count = 0;
		int left = candidates - 1, right = n - candidates;
		unordered_set<int> usedSet;
		priority_queue<Item, vector<Item>, Compare> pq1, pq2;
		for (int i = 0; i < candidates; ++i) {
			pq1.push(Item(costs[i], i));
			pq2.push(Item(costs[n-i-1], n-i-1));
		}
		while (left < n && right >= 0 && count < k) {
			cout << "left = " << left << ", right = " << right << endl;
			Item lMin = pq1.top(), rMin = pq2.top();
			cout << "lMin.cost = " << lMin.cost << ", rMin.cost = " << rMin.cost << endl;
			cout << "lMin.index = " << lMin.index << ", rMin.index = " << rMin.index << endl;
			if (lMin.cost < rMin.cost) {
				res += (long long)lMin.cost;
				cout << "To add " << lMin.cost << endl;
				usedSet.insert(lMin.index);
				pq1.pop();
				left++;
				while (left < n) {
					if (usedSet.count(left) == 0) {
						pq1.push(Item(costs[left], left));
						break;
					}
					left++;
				}
			} else if (lMin.cost > rMin.cost) {
				res += (long long)rMin.cost;
				cout << "To add " << rMin.cost << endl;
				usedSet.insert(rMin.index);
				pq2.pop();
				right--;
				while (right >= 0) {
					if (usedSet.count(right) == 0) {
						pq2.push(Item(costs[right], right));
						break;
					}
					right--;
				}
			} else {
				cout << "To add " << lMin.cost << endl;
				if (lMin.index < rMin.index) {
					res += (long long)lMin.cost;
					usedSet.insert(lMin.index);
					pq1.pop();
					left++;
					while (left < n) {
						if (usedSet.count(left) == 0) {
							pq1.push(Item(costs[left], left));
							break;
						}
						left++;
					}
				} else if (rMin.index < lMin.index) {
					res += (long long)rMin.cost;
					usedSet.insert(rMin.index);
					pq2.pop();
					right--;
					while (right >= 0) {
						if (usedSet.count(right) == 0) {
							pq2.push(Item(costs[right], right));
							break;
						}
						right--;
					}
				} else {
					// a special case that left and right has overlapping
					cout << "\n ===== same value ===== \n" << endl;
					res += (long long)lMin.cost;
					usedSet.insert(lMin.index);
					pq1.pop();
					left++;
					while (left < n) {
						if (usedSet.count(left) == 0) {
							pq1.push(Item(costs[left], left));
							break;
						}
						left++;
					}
					pq2.pop();
					right--;
					while (right >= 0) {
						if (usedSet.count(right) == 0) {
							pq2.push(Item(costs[right], right));
							break;
						}
						right--;
					}
				}
			}
			count++;
			cout << endl << endl;
		}
		cout << "left = " << left << ", right = " << right << endl;
		cout << count << ", rest in pq1: " << pq1.size() << endl;
		while (count < k && !pq1.empty()) {
			Item lMin = pq1.top();
			res += (long long)lMin.cost;
			usedSet.insert(lMin.index);
			pq1.pop();
			count++;
		}
		return res;
    }
};

int main() {
	vector<int> costs {526,954,161,691,816,380,362,172,80,218,574,390,945,287,727,741,220,710,88,686,851,596,916,770,732,111,957,940,546,832,649,494,858,112,987,568,952,887,190,374,34,190,477,30,547,275,335,567,242,697,738,627,146,12,502,737,508,80,267,198,816,975,623,659,12,345,334,329,784,905,608,368,230,714,203,606,806,963,700,280,300,535,628,348,359,572,87,30,959,812,834};
	vector<int> orderCosts(costs.begin(), costs.end());
	sort(orderCosts.begin(), orderCosts.end());
	int res = 0;
	for (int i = 0; i < 72; ++i) {
		res += orderCosts[i];
	}
	cout << "Min costs = " << res << endl;
	int k = 72;
	int candidate = 48;
	cout << costs.size() << endl;
	cout << Solution().totalCost(costs, k, candidate) << endl;
	return 0;
}