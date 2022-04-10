#include "../header.h"

class KthLargest {
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums): size(k) {
        for (int num: nums) {
            pq.push(num);
            while (pq.size() > k) {
                pq.pop();
            }
        }        
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    string s;
    cin >> s;
    vector<int> nums = stringToIntegerVector(s);
    int k;
    cin >> k;
    KthLargest solution = KthLargest(k, nums);
    int a = 0;
    cin >> a;
    while (a != -1) {        
        cout << solution.add(a) << endl;
        cin >> a;
    }
    return 0;
}