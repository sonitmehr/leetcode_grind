class Solution {
public:
int inDegree[2001] = {0};
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<int> adj[n + 1];
        for(auto i : v){
            adj[i[0]].push_back(i[1]);
        }
        

        for(auto i : adj){
            for(auto j : i){
                inDegree[j] ++;
            }
        }
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(inDegree[i] == 0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            auto p = q.front();

            q.pop();
            ans.push_back(p);
            for(auto i : adj[p]){
                inDegree[i]--;
                if(inDegree[i] == 0)q.push(i);

            }

        }
        reverse(ans.begin(),ans.end());
        if(ans.size() == n)return ans;
        return {};
    }
};
