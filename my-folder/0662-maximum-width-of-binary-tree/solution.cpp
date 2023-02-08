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
        if(root == NULL)return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            long long mini = q.front().second;
            int first,last;
            for(int i = 0;i<n;i++){
                //first = 1e9,last = -1;
                auto p = q.front();
                q.pop();
                long long ind = p.second - mini;
                auto node = p.first;
                if(i == 0)first = ind;
                if(i == n - 1)last =ind;
                if(node->left != NULL)q.push({node->left,2*ind + 1});
                if(node -> right != NULL)q.push({node->right,2*ind + 2});

            }
            cout << first << " " << last << endl;
            ans = max(ans,last - first +  1);
        }
        return ans;
    }
};
