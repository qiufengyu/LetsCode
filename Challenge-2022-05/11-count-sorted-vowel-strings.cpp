#include "../header.h"

class Solution {
public:
    int countVowelStrings(int n) {
        // the problem equals to split n objects to 5 groups, and each group can have 0
        // equals to split n + 5 objects to 5 groups and each group has at least 1 object
        // there are (n + 5 - 1) slots to put 4 splitters => (n + 4) choose 4
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};