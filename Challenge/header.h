#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "linked_list.h"
#include "binary_tree.h"

using namespace std;

void print_vector(vector<vector<int>>& v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        cout << "[";
        for(int j = 0; j < v[i].size() - 1; j++) {
            cout << v[i][j] << ", ";
        }
        cout << v[i][v[i].size() - 1];
        cout << "],";
    }
    cout << "]"<<endl;
}