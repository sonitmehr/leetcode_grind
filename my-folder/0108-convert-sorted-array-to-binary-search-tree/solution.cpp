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
    vector<int> v;
    TreeNode * f(int l,int r){
        if(l > r)return NULL;
        int mid = (l+r)/2;
        TreeNode * root = new TreeNode(v[mid]);
        
        root -> left = f(l,mid-1);
        root -> right = f(mid+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n = v.size();
        this->v =v;
        int l = 0,r = n-1;
        TreeNode* root = NULL;
        return f(l,r);
    }
};
