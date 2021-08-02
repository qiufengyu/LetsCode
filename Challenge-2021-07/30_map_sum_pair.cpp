#include "../header.h"

struct Trie {
    char c;
    int val;
    Trie* children[26];
    Trie(char ch): c(ch), val(0) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class MapSum {
    Trie *root;
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Trie('0');
    }
    
    void insert(string key, int val) {
        int temp = val - m[key];
        m[key] = val;
        Trie *current = root;
        for (int i = 0; i < key.size(); ++i) {
            int idx = key[i] - 'a';
            Trie *child = current->children[idx];
            if (child != nullptr) {
                child->val += temp;
            } else {
                current->children[idx] = new Trie(key[i]);
                current->children[idx]->val = val;
                child = current->children[idx];
            }
            current = child;
        }        
    }
    
    int sum(string prefix) {
        Trie* current = root;
        for (int i = 0; i < prefix.size(); ++i) {
            current = current->children[prefix[i] - 'a'];
            if (current == nullptr) {
                return 0;
            }
        }      
        return current->val;
    }
};

int main() {
    MapSum *mapSum = new MapSum();
    mapSum->insert("apple", 3);
    cout << mapSum->sum("ap") << endl;
    mapSum->insert("app", 2);
    cout << mapSum->sum("ap") << endl;
    return 0;
}

