/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTIterator {
private : 
    void insert(TreeNode* root, stack<TreeNode*>& st) {

        while (root != NULL) {
            st.push(root);
            if (reverse) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }
public:
    stack<TreeNode*> st;
    bool reverse;


    BSTIterator(TreeNode* root, bool reverse) {
        this->reverse = reverse;
        insert(root, st);
    }

    int next() {

        auto top = st.top();
        int val = top->val;
        st.pop();
        if (reverse) {
            insert(top->left, st);
        } else {
            insert(top->right, st);
        }

        return val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int left = l.next();
        int right = r.next();

        while (left < right) {
            int sum = left + right;
            if (k == sum)
                return true;
            else if (sum > k) {
                right = r.next();
            } else {
                left = l.next();
            }
        }
        return false;
    }
};
