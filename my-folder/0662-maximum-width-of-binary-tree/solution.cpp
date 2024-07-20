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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        long long ans = 0;
        while(!q.empty()){

            int sz = q.size();
            long long mini = 1e9,maxi = -1e9;
            long long minus = q.front().second;
            // cout << minus << endl;
            for(int k = 0;k<sz;k++){
                auto p = q.front();
                q.pop();
                
                TreeNode * node = p.first;
                long long ind = p.second - minus;
                
                mini = min(mini,ind);
                maxi = max(maxi,ind);
                
                if(node->left != NULL){
                    q.push({node->left,2*ind + 1});
                }
                if(node->right != NULL){
                    q.push({node->right,2*ind + 2});
                }

            }
            ans = max(ans,maxi - mini + 1);
        }
        return ans;
    }
};
