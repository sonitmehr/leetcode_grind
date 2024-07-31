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

    void solve(TreeNode* root,TreeNode* prev){
        if(root==NULL)return;

        solve(root->left,root);
        solve(root->right,root);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        solve(root,NULL);
    //    solve(root->left,root);
    //    solve(root->right,root);
       return root;
    }
};
