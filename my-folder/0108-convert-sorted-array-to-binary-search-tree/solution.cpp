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
    
    TreeNode * f(vector<int> & v){
        if(v.size() == 0)return NULL;
        int mid = v.size()/2;
        
        TreeNode * head = new TreeNode(v[mid]);
        
        vector<int> left(v.begin(),v.begin() + mid);
        vector<int> right(v.begin() + mid + 1,v.end());
        
        head -> left = f(left);
        head -> right = f(right);
        
        return head;
        
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();
        if(n == 0) return NULL;
        if(n == 1)return new TreeNode(v[0]);
        
        int mid = n/2;
        
        
        
        TreeNode* head = new TreeNode(v[mid]);
        return f(v);
    }
};
