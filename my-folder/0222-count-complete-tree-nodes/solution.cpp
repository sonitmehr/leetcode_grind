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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL)return 0;
        q.push(root);

        int ans=0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            ans ++;
            if(p -> left != NULL){
                q.push(p->left);
            }
            if(p -> right != NULL){
                q.push(p->right);
            }
        }
        return ans;
    }
};
