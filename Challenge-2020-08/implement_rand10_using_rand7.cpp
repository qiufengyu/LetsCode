#include "../header.h"

int rand7() {
    return rand() % 7 + 1;
}

class Solution {
public:
    int rand10() {
        int temp = 40;
        while (temp >= 40) {
            temp = 7 * (rand7() - 1) + (rand7() - 1);
        }
        return temp % 10 + 1;
    }
};

