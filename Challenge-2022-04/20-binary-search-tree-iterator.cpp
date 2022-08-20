#include "../header.h"

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        // root can't be nullptr
        TreeNode *t = root;
        while (t) {
            st.push(t);
            t = t->left;
        }
    }
    
    int next() {        
        TreeNode *t = st.top();        
        st.pop();
        int res = t->val;
        t = t->right;
        while (t) {
            st.push(t);
            t = t->left;
        }        
        return res;
    }
    
    bool hasNext() {
        return !st.empty();        
    }
};