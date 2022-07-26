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
    TreeNode * bfs(TreeNode* root, TreeNode* p, TreeNode* q){
        
        //int vp = p -> val;
        //int vq = q -> val;
        if(p -> val > root-> val && q -> val > root-> val )return bfs(root->right,p,q);
        
        else if(p -> val < root -> val && q -> val < root -> val) return bfs(root -> left,p,q);
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p -> val == root-> val || q-> val == root->val || root == NULL)return root;
         
        
        return bfs(root,p,q);
    }
};
