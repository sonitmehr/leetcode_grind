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
        long long  ans = 0;
        while(!q.empty()){
            int sz = q.size();

            long long minus = q.front().second;
            long long mini = INT_MAX,maxi = INT_MIN;
            for(int k = 0;k<sz;k++){

                auto p = q.front();
                q.pop();

                auto node = p.first;
                long long index = p.second - minus;
                cout << index << endl;
                mini = min(mini,index);
                maxi = max(maxi,index);

                if(node ->left != NULL){
                    q.push({node->left,2*index + 1});
                }
                if(node ->right != NULL){
                    q.push({node->right,2*index + 2});
                }
            }
            ans = max(ans,maxi - mini + 1);

        }
        return ans;

    }
};
