#include "../header.h"


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(grid, 0, 0, n-1, n-1);
    }

    Node* helper(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        int n = grid.size();
        if (r1 > r2 || c1 > c2 || r1 < 0 || r2 >= n || c1 < 0 || c2 >= n) {
            return nullptr;
        }
        bool isLeaf = true;
        int val = grid[r1][c1];
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) {
                break;
            }
        }
        if (isLeaf) {
            return new Node(val, true);
        }
        // we can divide into four sub grids
        int rm = (r1 + r2) / 2, cm = (c1 + c2) / 2;
        Node *topLeft = helper(grid, r1, c1, rm, cm);
        Node *topRight = helper(grid, r1, cm+1, rm, c2);
        Node *bottomLeft = helper(grid, rm+1, c1, r2, cm);
        Node *bottomRight = helper(grid, rm+1, cm+1, r2, c2);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};