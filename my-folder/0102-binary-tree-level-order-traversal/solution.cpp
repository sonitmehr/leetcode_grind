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
    
    void print(vector<int> &v){
        for(int i = 0;i<v.size();i++)cout << v[i] << " ";
        cout << endl;
    }
    void f(TreeNode* root,int height,vector<vector<int>> &ds){
        if(root == NULL)return;
        
        cout << "Height " << height << " ds.size() == " << ds.size() << endl;
        //print(v);
        if(height == ds.size()){            
            ds.push_back({});            
            //v.clear();
        }
        ds[height].push_back(root->val);
        
        
        f(root->left,height+1,ds);
        f(root->right,height+1,ds);
        
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ds;
        vector<int> v;
        
        if(root == NULL)return {};
        
        int height = 0,val = root->val;
        ds.push_back({});
        
        f(root,height,ds);
        
        //f(root->right,v,ds,0);
        
        return ds;
    }
};
