/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, int result) {
        if (root == NULL)
            return;
        int val = root->val;
        int newFrequency = result ^ (1 << val);

        if (root->left == NULL && root->right == NULL) {
            if ((newFrequency & (newFrequency - 1)) == 0) {
                ans++;
            }
        }
        solve(root->left, newFrequency);
        solve(root->right, newFrequency);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};
