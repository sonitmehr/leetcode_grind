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
TreeNode* solve(vector<int>& post, vector<int>& in,
                    unordered_map<int, int>& mp, int postStart, int postEnd,
                    int inStart, int inEnd) {

        if(postStart > postEnd || inStart > inEnd)return NULL;

        int newRoot = post[postEnd];
        int ind = mp[newRoot];
        int right = inEnd -ind;
        

        TreeNode* root = new TreeNode(newRoot);

        root->right = solve(post,in,mp,postEnd - right,postEnd - 1,ind + 1,inEnd);
        root->left = solve(post,in,mp,postStart,postEnd-right-1,inStart,ind - 1);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
         int n = post.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[in[i]] = i;
        }

        return solve(post, in, mp,0,n - 1,0,n - 1);
    }
};
