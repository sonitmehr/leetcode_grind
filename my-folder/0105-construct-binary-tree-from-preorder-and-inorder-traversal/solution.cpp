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
    TreeNode* solve(vector<int>& pre, vector<int>& in,
                    unordered_map<int, int>& mp, int preStart, int preEnd,
                    int inStart, int inEnd) {

        if(preStart > preEnd || inStart > inEnd)return NULL;

        int newRoot = pre[preStart];
        int ind = mp[newRoot];
        int left = ind - inStart;

        TreeNode* root = new TreeNode(newRoot);

        root->left = solve(pre,in,mp,preStart + 1,preStart + left,inStart,ind - 1);
        root->right = solve(pre,in,mp,preStart+left+1,preEnd,ind + 1,inEnd);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[in[i]] = i;
        }

        return solve(pre, in, mp,0,n - 1,0,n - 1);
    }
};
