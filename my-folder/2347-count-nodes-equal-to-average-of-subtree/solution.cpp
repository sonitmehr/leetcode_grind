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
    int ans;
    pair<int,int> dfs(TreeNode* root){
        
        if(root == NULL)return {0,0};
            
                
        pair<int,int> pLeft = dfs(root->left);
        int leftSum = pLeft.first;
        int leftCount = pLeft.second;
        
        pair<int,int> pRight = dfs(root->right);
        int rightSum = pRight.first;
        int rightCount = pRight.second;
        
        int cnt = leftCount + rightCount + 1;
        int sum = leftSum + rightSum + root->val;
        
        if(root->val == sum/cnt)ans++;
        
        return {sum,cnt};
          
    }
    
    int averageOfSubtree(TreeNode* root) {
        //n = 0;
        ans = 0;
        dfs(root);
        
        return ans;
        
    }
};
