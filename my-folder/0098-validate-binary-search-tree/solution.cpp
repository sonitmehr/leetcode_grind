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

    bool solve(TreeNode* root,long long mini,long long maxi){
        if(root==NULL)return true;
        cout << mini << " " << maxi << endl;
        if(root->val <= mini || root->val >= maxi)return false;

        bool left = solve(root->left,mini,root->val);
        bool right = solve(root->right,root->val,maxi);

        if(left == false)return false;
        if(right == false)return false;

        return true;


    }

    bool isValidBST(TreeNode* root) {
        
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};
