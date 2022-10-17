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
    void  f(TreeNode * root,int val){
        if(root == NULL)return;
        if(root->left == NULL && root->right==NULL){
            val = 10*val + root->val;
            //cout << "valS " << val << endl;
            sum += val;
        }
        else {
            val = 10*val + root->val;
            
            //cout << "val " << val << endl;
            f(root->left,val);

            f(root->right,val);
        }
    }
    int sumNumbers(TreeNode* root) {
        f(root,0);
        return sum;
    }
};
