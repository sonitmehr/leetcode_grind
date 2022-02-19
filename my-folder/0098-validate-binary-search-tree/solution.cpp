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
private: TreeNode* perv;
public:
    bool isValidBST(TreeNode* root) {
        if(root){
            if(!isValidBST(root->left))
                return false;
            if(perv && root->val <= perv->val)
                return false;
            perv=root;
            return isValidBST(root->right);
        }//end if
        return true;
    }
};
