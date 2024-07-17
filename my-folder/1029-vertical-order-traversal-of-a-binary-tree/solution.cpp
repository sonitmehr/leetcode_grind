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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // node,vlevel,hlevel
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        

        q.push({root,{0,0}});
        
        map<int,map<int,multiset<int>>> mp;
        
        while(!q.empty()){
            
            auto p = q.front();
            
            q.pop();
            
            
            TreeNode* node = p.first;
            int vlevel = p.second.first;
            int hlevel = p.second.second;
            
            mp[vlevel][hlevel].insert(node->val);
            
            if(node -> left != NULL){
                q.push({node->left,{vlevel - 1,hlevel + 1}});
            }
            if(node -> right != NULL){
                q.push({node->right,{vlevel + 1,hlevel + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto &i : mp){
            vector<int> vec;
            
            for(auto &j : i.second){
                for(auto it = j.second.begin();it != j.second.end();it++){

                    vec.push_back(*it);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};
