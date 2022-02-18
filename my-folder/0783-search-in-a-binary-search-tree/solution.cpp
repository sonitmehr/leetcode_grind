/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct TreeNode* searchBST(struct TreeNode* root, int val){
    if (!root) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    
    struct TreeNode* root_l = searchBST(root->left, val);
    struct TreeNode* root_r = searchBST(root->right, val);
    
    if (root_l) {
        return root_l;
    }
    
    else if (root_r) {
        return root_r;
    }
    
    return NULL;
}
};
