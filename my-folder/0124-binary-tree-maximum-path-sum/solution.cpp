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

    int solve(TreeNode * root,int &maxi){
        if(root == NULL)return 0;

        int left = solve(root->left,maxi);
        int right = solve(root->right,maxi);

        maxi = max({maxi,root->val,left + right + root->val,root->val,root->val + left,root->val + right});

        return root->val + max({left,right,0});
    }

    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;

        solve(root,maxi);
        return maxi;
    }
};
