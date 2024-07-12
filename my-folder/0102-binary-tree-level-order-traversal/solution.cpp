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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == NULL)
            return {};
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {

            vector<int> vec;
            int sz = q.size();
            for (int i =0;i<sz;i++) {
                auto p = q.front();
                vec.push_back(p->val);
                if (p->left != NULL) {
                    q.push(p->left);
                }
                if (p->right != NULL) {
                    q.push(p->right);
                }
                q.pop();
            }
            ans.push_back(vec);
        }

        return ans;
    }
};
