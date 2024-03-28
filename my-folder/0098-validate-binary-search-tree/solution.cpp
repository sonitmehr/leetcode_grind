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

    int maxValue(TreeNode * root){
        if(root == NULL)return INT_MIN;

        int value = root->val;

        int left = maxValue(root->left);
        int right = maxValue(root->right);

        return max(value,max(left,right));
    }
    int minValue(TreeNode * root){
        if(root == NULL)return INT_MAX;

        int value = root->val;

        int left = minValue(root->left);
        int right = minValue(root->right);

        return min(value,min(left,right));
    }

    bool isValidBST(TreeNode* root) {
        
        if(root == NULL)return true;
        int val = root->val;
        if(root->left != NULL && maxValue(root->left) >= val)return false;
        if(root->right != NULL && minValue(root->right) <= val)return false;

        if(!isValidBST(root->left)  || !isValidBST(root->right))return false;

        return true;


    }
};
