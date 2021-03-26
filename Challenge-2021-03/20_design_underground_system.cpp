#include "../header.h"

class UndergroundSystem {
    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<double, int>> histories;
public:
    UndergroundSystem() {
        in.reserve(20000);
        histories.reserve(20000);
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if (in.count(id)) {
            auto r = in[id];
            string fromTo = r.first + "-" + stationName;
            int cost = t - r.second;
            histories[fromTo].first += cost;
            histories[fromTo].second += 1;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string q = startStation + "-" + endStation;
        if (histories.count(q)) {
            return histories[q].first / histories[q].second;
        }
        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */