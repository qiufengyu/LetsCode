#include "../header.h"

class BrowserHistory {
    vector<string> histories;
    int size;
    int current;
public:
    BrowserHistory(string homepage): size{1}, current{0} {
        histories.push_back(homepage);
    }
    
    void visit(string url) {
        if (current == histories.size() - 1) {
            histories.push_back(url);
            size = histories.size();
            current++;
        } else {
            current++;
            histories[current] = url;
            size = current + 1;
        }
    }
    
    string back(int steps) {
        current = max(current - steps, 0);
        return histories[current];
    }
    
    string forward(int steps) {
        current = min(size - 1, current + steps);
        return histories[current];
    }
};