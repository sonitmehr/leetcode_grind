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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root==NULL)return {};
        st.push(root);
        vector<int> ans;
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            ans.push_back(p->val);
            if(p->right != NULL){
                st.push(p->right);
            }
            if(p->left != NULL){
                st.push(p->left);
            }

        }
        return ans;
    }
};
