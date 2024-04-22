#include "../header.h"

class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> ds(deadends.begin(), deadends.end());
		unordered_set<string> vs;
		for (auto const& d: deadends) {
			ds.insert(d);
		}
		string start = "0000";
		if (ds.count(start)) {
			return -1;
		}
		queue<string> q;
		q.push(start);
		int res = 0;
		while (q.size() > 0) {
			int sz = q.size();
			while (sz) {
				string frt = q.front();
				q.pop();
				if (frt == target) {
					return res;
				}
				vector<string> nxt = nextLock(frt, ds, vs);
				for (auto const& n: nxt) {
					q.push(n);
				}
				sz--;
			}
			res++;
		}
		return -1;
	}

	vector<char> nextNumber(char n) {
		vector<char> res(2, '0');
		if (n == '0') {
			res[0] = '9';
			res[1] = '1';
		} else if (n == '9') {
			res[0] = '8';
			res[1] = '0';
		} else {
			res[0] = n - 1;
			res[1] = n + 1;
		}
		return res;		
	}

    vector<string> nextLock(string frt,
                        const unordered_set<string>& ds,
						unordered_set<string>& vs) {
		vector<string> nxt;
		for (int i = 0; i < 4; i++) {
			char c = frt[i];
			for (auto const x: nextNumber(c)) {
				string nfrt = frt;
				nfrt[i] = x;
				if (ds.count(nfrt) == 0 && vs.count(nfrt) == 0) {
					nxt.push_back(nfrt);
					vs.insert(nfrt);
				}
			}
		}
		return nxt;
	}
};


int main() {
	vector<string> s{"8887","8889","8878","8898","8788","8988","7888","9888"};
	string target = "8888";
	cout << Solution().openLock(s, target) << endl;
	return 0;
}

