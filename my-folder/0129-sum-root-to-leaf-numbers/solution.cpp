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
    int sum = 0;
    void solve(TreeNode * root,int currVal){

        if(root == NULL)return ;

        if(root->left == NULL && root->right == NULL){
        int val = root->val;
            currVal = 10*currVal + val;
            sum += currVal;
            return;
        }
        int val = root->val;

        currVal = 10*currVal + val;
        solve(root->left,currVal);
        solve(root->right,currVal);


    }

    int sumNumbers(TreeNode* root) {
        
            solve(root,0);

            return sum;

    }
};
