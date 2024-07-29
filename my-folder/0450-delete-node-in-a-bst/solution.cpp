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

    TreeNode* findLeftMost(TreeNode* root){
        if(root->left == NULL)return root;
        return findLeftMost(root->left);
    }

    TreeNode* findNode(TreeNode* root){
        if(root->right == NULL)return root->left;
        if(root->left == NULL)return root->right;

        TreeNode* left = root->left;
        TreeNode* leftMost = findLeftMost(root->right);

        leftMost -> left = left;

        return root->right;

    }

    TreeNode* solve(TreeNode* root,int k){
        
        if(root==NULL)return NULL;
        if(root->val==k)return findNode(root);
        TreeNode* temp = root;

        while(temp != NULL){
            int val = temp ->val;
            
            if(k > val){
                
                if(temp->right != NULL && temp->right->val == k){
                    temp -> right = findNode(temp->right);
                    break;
                }

                temp = temp ->right;

            }
            else{
                if(temp->left != NULL && temp->left->val == k){
                    temp -> left = findNode(temp->left);
                    break;
                }
                temp = temp -> left;
            }

        }

        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};
