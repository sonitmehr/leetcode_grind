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
    int maxi = 0;
    int mini = 0;
    int solve(TreeNode * root,int &val){
        if(root != NULL){

            
            int left = solve(root->left,val);
            int right = solve(root->right,val);

            val = max(val, left + right);

            return max (left,right) + 1; 
        }
        return 0;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int val = 0;
        solve(root,val);
        return val;
    }
};
