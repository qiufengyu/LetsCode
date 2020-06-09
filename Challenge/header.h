#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
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