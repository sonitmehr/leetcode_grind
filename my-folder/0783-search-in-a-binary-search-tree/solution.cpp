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

    TreeNode* solve(TreeNode* root,int val){
        if(root == NULL)return NULL;

        if(root->val == val)return root;
        TreeNode* left = solve(root->left,val);
        TreeNode* right = solve(root->right,val);

        if(left != NULL)return left;
        return right;

    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};
