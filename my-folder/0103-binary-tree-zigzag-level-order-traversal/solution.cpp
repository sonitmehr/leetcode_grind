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
    vector<vector<int>> ans;
    vector<vector<int>> solve(TreeNode* root){
        
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            
            int n = q.size();
            vector<int> vec;
            for(int i = 0;i<n;i++){
                auto p = q.front();
                q.pop();
                vec.push_back(p->val);
                if(p->left != NULL){
                    q.push(p->left);
                }
                if(p->right != NULL){
                    q.push(p->right);
                }
            }

            if(flag){
                reverse(vec.begin(),vec.end());
            }
            ans.push_back(vec);
           flag = !flag;

        }
        return ans;

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return solve(root);
    }
};
