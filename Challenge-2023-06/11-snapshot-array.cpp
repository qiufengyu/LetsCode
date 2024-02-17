#include "../header.h"

class SnapshotArray {
    int currentSnap;
    vector<map<int, int>> m;
public:
    SnapshotArray(int length) {
        m.resize(length);
        currentSnap = 0;  
        for (int i = 0; i < length; ++i) {
            m[i][0] = 0;
        }      
    }
    
    void set(int index, int val) {
        m[index][currentSnap] = val;
    }
    
    int snap() {
        return currentSnap++;
    }
    
    int get(int index, int snap_id) {
        if (m[index].count(snap_id) == 0) {
            auto it = --m[index].lower_bound(snap_id);
            return it->second;
        }
        return m[index][snap_id];
    }
};