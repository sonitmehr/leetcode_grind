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
    int ans = 0;
    void solve(TreeNode* root,int val){
        if(root == NULL)return;
        
        
        int xorVal = 1 << root->val;
        
        val = val ^ xorVal;

        if(root -> left == NULL && root->right == NULL){
            int check = val & -val;
            if(check == 0 || check == val)ans++;
            
            return;
        }
        solve(root->left,val);
        solve(root->right,val);

    }

    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        solve(root,0);
        return ans;
    }
};
