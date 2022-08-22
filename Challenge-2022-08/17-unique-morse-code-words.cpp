#include "../header.h"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string m[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for (string const& word: words) {
            string temp = "";
            for (char const c: word) {
                temp += m[c-'a'];
            }
            st.insert(temp);
        }
        return (int)st.size();
    }
};
