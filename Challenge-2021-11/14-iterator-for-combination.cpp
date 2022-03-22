#include "../header.h"

class CombinationIterator {
    set<string> _v;
public:
    CombinationIterator(string characters, int combinationLength) {
        string current = "";
        int sz = characters.size();
        bitset<15> bs;
        for (int i = 0; i < sz; ++i) {
            helper(characters, combinationLength, sz, current, i, bs);
            current.pop_back();
            bs.set(i, 0);
        }
    }
    
    void helper(const string characters, const int combination, const int size, string& current, int currentIndex, bitset<15>& bs) {
        bs.set(currentIndex, 1);
        current.push_back(characters[currentIndex]);    
        if (current.size() == combination) {
            _v.insert(current);
        } else {
            for (int i = currentIndex + 1; i < size; ++i) {
                if (bs[i] == 0) {
                    helper(characters, combination, size, current, i, bs);
                    bs.set(i, 0);
                    current.pop_back();
                }
            }
        }
    }
    
    string next() {
        string n =  *(_v.begin());
        _v.erase(_v.begin());
        return n;
    }
    
    bool hasNext() {
        return _v.size() > 0;
    }
};

int main() {
    string s;
    int cl;
    cin >> s;
    cin >> cl;
    CombinationIterator itr(s, cl);
    cout << itr.next() << endl;    // return "ab"
    cout << itr.hasNext() << endl; // return True
    cout << itr.next() << endl;    // return "ac"
    cout << itr.hasNext() << endl; // return True
    cout << itr.next() << endl;    // return "bc"
    cout << itr.hasNext() << endl; // return False
}