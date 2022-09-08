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
    TreeNode * f(TreeNode* root, int p,int q){
        if(root == NULL)return root;
        int val = root->val;
        
        if(root->val < q && p > root->val) return f(root->right,p,q);
        else if(root->val >q && root->val > p) return f(root->left,p,q);
        return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return f(root,p->val,q->val);
    }
};
