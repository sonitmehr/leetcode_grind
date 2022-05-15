class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {  
      vector<vector<int >>v;

        if(root==nullptr)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>vi;
            for(int i=0;i<n;i++){
                TreeNode*p= q.front();
            vi.push_back(p->val);
            q.pop(); 
                if(p->left!=nullptr)
                q.push(p->left);
                if(p->right!=nullptr)
                q.push(p->right);
            }
           v.push_back(vi);
        }
        
        return v;
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>v= levelOrder(root);
        int sum=0;
        int n=v.size()-1;
        for(int i=0;i<v[n].size();i++){
            sum+=v[n][i];
        }
        return sum;
    }
};
