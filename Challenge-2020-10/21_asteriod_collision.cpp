#include "../header.h"

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                v.push_back(asteroids[i]);
            } else if (v.size() == 0 || v.back() < 0) {
                v.push_back(asteroids[i]);
            } else if (v.back() <= -asteroids[i]) {
                if (v.back() < -asteroids[i]) {
                    i--;
                }
                v.pop_back();
            }
        }
        return v;
    }
};

int main() {

}