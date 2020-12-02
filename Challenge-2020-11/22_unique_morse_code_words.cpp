#include "../header.h"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dict {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for (auto& word: words) {
            string temp {""};
            for (auto& c: word) {
                temp += dict[c-'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};