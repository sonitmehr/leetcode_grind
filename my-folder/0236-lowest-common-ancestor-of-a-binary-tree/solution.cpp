/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(TreeNode * root,int p,int q){
        if(root==NULL)return NULL;

        if(root->val == p || root-> val == q)return root;

        TreeNode * left=  solve(root->left,p,q);
        TreeNode * right=  solve(root->right,p,q);

        if(left != NULL && right != NULL)return root;
        else if(left != NULL)return left;
        return right; 

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* P, TreeNode* Q) {
        int p = P->val;
        int q = Q->val;
        return solve(root,p,q);
        
    }
};
