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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)return new TreeNode(val);
        TreeNode* temp = root;
        while(temp != NULL){
            int curr = temp->val;
            if(val > curr){
                if(temp->right == NULL){
                    temp->right = new TreeNode(val);
                    break;
                }
                temp = temp -> right;

            }
            else{
                if(temp->left == NULL){
                    temp->left = new TreeNode(val);
                    break;
                }
                temp = temp ->left;
            }
        }
        return root;
    }
};
