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

    bool isSameTree(TreeNode* p,TreeNode* q){
        if(p == NULL || q == NULL)return p == q;

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        

        return p->val == q->val && left && right;
    }

    bool traverse(TreeNode* root, TreeNode* subRoot){
        if(root == NULL)return false;

        if(traverse(root->left,subRoot) == true)return true;

        if(isSameTree(root,subRoot))return true;

        if(traverse(root->right,subRoot) == true)return true;

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverse(root,subRoot);
    }
};
