/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* node ,TreeNode* par,unordered_map<TreeNode*,TreeNode*> &mp,int dist,int k){
        if(node == NULL)return;
        // cout << node->val << " " << dist <<  endl;
        if(dist == k){
            ans.push_back(node->val);
            return ;
        }

        if(node->left != NULL && node->left != par){
            dfs(node->left,node,mp,dist + 1,k);
        }       
        if(node->right != NULL && node->right != par){
            dfs(node->right,node,mp,dist + 1,k);
        }       
        if(mp[node] != par){
            dfs(mp[node],node,mp,dist + 1,k);
        }

    }

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;

        q.push(root);
        unordered_map<TreeNode*,TreeNode*> mp;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            

          
            
            if(p->left != NULL){
                mp[p->left] = p;
                q.push(p->left);
            }
            if(p->right != NULL){
                mp[p->right] = p;
                q.push(p->right);
            }
        }
        dfs(target,NULL,mp,0,k);
return ans;


    }
};
