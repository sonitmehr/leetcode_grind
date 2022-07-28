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
    
    TreeNode * f(TreeNode * root){
        if(root == NULL)return root;
        
        TreeNode * l = f(root -> left);
        TreeNode * r = f(root -> right);
        
        if(root -> left != NULL){
            if(l !=NULL){
                l -> right = root -> right;
                root -> right = root -> left;
                root -> left = NULL;
            }
        }
        if(r != NULL)return r;
        else if(l != NULL)return l;
        else return root;
            
        
        
    }
    
    void flatten(TreeNode* root) {
        root = f(root);
    }
};
