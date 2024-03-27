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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;\
        if(root==NULL)return {};
        q.push({root,0});

        int val = 0;
        int currLevel = 0;
        vector<vector<int>> ans;
        vector<int> vec;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            TreeNode* currNode = curr.first;
            int level = curr.second;
            if(level != currLevel){
                if(val == 1)reverse(vec.begin(),vec.end());
                val = !val;
                ans.push_back(vec);
                vec.clear();
                currLevel = level;
            }
            vec.push_back(currNode->val);
            
            if(currNode->left != NULL){
                q.push({currNode->left,level+ 1});
            }
            if(currNode->right != NULL){
                q.push({currNode->right,level+ 1});

            }

            

        }
        if(vec.size() > 0){
             if(val == 1)reverse(vec.begin(),vec.end());
                val = !val;
                ans.push_back(vec);
                vec.clear();
        }
        return ans;
    }
};
