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

    TreeNode* solve(int &i,vector<int>& pre,int ub){
        if(i >= pre.size())return NULL;
        TreeNode* root = NULL;
        

        if(pre[i] < ub){
            root = new TreeNode(pre[i++]);
            root->left = solve(i,pre,root->val); 
            root->right = solve(i,pre,ub);
        }
        




        return root;

    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i = 0;
        return solve(i,pre,INT_MAX);
    }
};
