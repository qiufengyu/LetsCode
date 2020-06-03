#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Group {
    int price;
    int nextIndex;
    int days;
    Group(int p, int n, int d): price{p}, nextIndex{n}, days{d} {}
};

class StockSpanner {
    stack<pair<int, int>> s;
public:
    StockSpanner() {}
    int next(int price) {
        int d = 1;
        while(!s.empty() && price >= s.top().first) {
            d += s.top().second;
            s.pop();
        }
        s.push(make_pair(price, d));
        return d;
    }
};

/*
class StockSpanner {
    vector<Group> v;
    int size;
public:
    StockSpanner() {
        v.push_back(Group{100001, -1, 1});
        size = 0;
    }
    
    int next(int price) {
        Group prev = v[size];
        if (price < prev.price) {
            v.push_back(Group{price, size, 1});
        }
        else {
            int d = 1;
            int n = size;
            while (price >= prev.price) {
                d += prev.days;
                n = prev.nextIndex;
                prev = v[n];
            }
            v.push_back(Group{price, n, d});
        }
        size += 1;
        return v[size].days;
    }
};
*/

int main() {
    int price;
    StockSpanner* obj = new StockSpanner();
    while (cin >> price) {
        cout << obj->next(price) << endl;
    }
    return 0;
}
