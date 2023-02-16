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
    void f(TreeNode* root,int val){
        if(root==NULL)return;
        if(root->left == NULL && root->right == NULL){
            ans = max(ans,val);
            return;
        }
        f(root->left,val + 1);
        f(root->right,val+1);
    }
    int maxDepth(TreeNode* root) {
        f(root,1);
        return ans;
    }
};
