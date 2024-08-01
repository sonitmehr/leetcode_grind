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

    void solve(TreeNode* root,int &cnt,int maxi){
        if(root == NULL)return;

        maxi = max(maxi,root->val);
        if(root->val >= maxi)cnt++;

        solve(root->left,cnt,maxi);
        solve(root->right,cnt,maxi);
    }

    int goodNodes(TreeNode* root) {
        int cnt =0;
        solve(root,cnt,-1e4-1);
        return cnt;
    }
};
