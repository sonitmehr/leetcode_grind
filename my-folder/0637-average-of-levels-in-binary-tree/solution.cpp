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
    
    void dfs(TreeNode * root,map<int,vector<double>> &m,int level){
        if (root == NULL)return;
        
        dfs(root->left,m,level+1);
        dfs(root->right,m,level+1);
        m[level].push_back(root->val);
        return;
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,vector<double>> m;
        dfs(root,m,1);
        int n = m.size();
        vector<double> ans;
        for(auto i : m){
            double sum = 0,cnt = 0;
            for(auto j : i.second){
                sum += j;
                cnt++;
            }
            ans.push_back(sum/cnt);
        }
        return ans;
        
    }
};
