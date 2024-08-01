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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)return root;


        int val = root->val;
        int p_val = p->val;
        int q_val = q->val;
        if(p_val > val && q_val > val){
            return solve(root->right,p,q);
        }
        else if(p_val < val && q_val < val){
            return solve(root->left,p,q);

        }

        return root;
        


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);   
    }
};
