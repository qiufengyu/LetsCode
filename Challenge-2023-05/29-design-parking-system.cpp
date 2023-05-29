#include "../header.h"

class ParkingSystem {
    vector<int> slots;
public:
    ParkingSystem(int big, int medium, int small) {
        slots.push_back(big);
        slots.push_back(medium);
        slots.push_back(small);
    }
    
    bool addCar(int carType) {
        if (slots[carType - 1] > 0) {
            slots[carType - 1] = slots[carType - 1] - 1;
            return true;
        }
        return false;
    }
};
