#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include "linked_list.h"
#include "binary_tree.h"

using namespace std;

void print2DVector(vector<vector<int>>& v) {
    for (auto& i: v) {
        for (auto& j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}