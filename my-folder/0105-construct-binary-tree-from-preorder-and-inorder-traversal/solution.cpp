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
   
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {

        return f(pre,0,pre.size(),in,0,in.size());
    
    }

    TreeNode* f(vector<int>& pre,int i,int j,vector<int>& in,int ii,int jj)
    {
        //    8 4 5 3 7 3
        //    8 [4 3 3 7] [5]
        //      [3 3 4 7] 8 [5]

       
        if(i >= j || ii >= j)
            return NULL;

        int mid = pre[i];
        auto ind = find(in.begin() + ii,in.begin() + jj,mid);

        int dis = ind - in.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = f(pre,i + 1,i + 1 + dis,in,ii,ii + dis);
        root -> right = f(pre,i + 1 + dis,j,in,ii + dis + 1,jj);
        return root;
    }
};
