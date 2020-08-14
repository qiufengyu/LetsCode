#include "../header.h"

class CombinationIterator {
    vector<string> combs;
    int index;
    void makeCombs(const string& characters, const int combinationLength, string temp, int start) {
        if (temp.length() == combinationLength) {
            combs.push_back(temp);
            return;
        } else {
            for (int i = start; i < characters.length(); i++) {
                makeCombs(characters, combinationLength, temp + characters[i], i + 1);
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        index = 0;
        makeCombs(characters, combinationLength, "", 0);
    }
    
    string next() {
        index++;
        return combs[index - 1];
    }
    
    bool hasNext() {
        return index < combs.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    CombinationIterator iterator = CombinationIterator("abc", 2); // creates the iterator.
    cout << iterator.next() << endl;// returns "ab"
    cout << iterator.hasNext() << endl; // returns true
    cout << iterator.next() << endl; // returns "ac"
    cout << iterator.hasNext() << endl; // returns true
    cout << iterator.next() << endl; // returns "bc"
    cout << iterator.hasNext() << endl; // returns false
    return 0;
}