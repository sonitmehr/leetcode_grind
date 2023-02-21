class Solution {
public:
    int inDegree[2001] = {0};
    bool canFinish(int n, vector<vector<int>>& v) {
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
        int cnt = 0;
        while(!q.empty()){
            auto p = q.front();

            q.pop();
            cnt++;
            for(auto i : adj[p]){
                inDegree[i]--;
                if(inDegree[i] == 0)q.push(i);

            }

        }
        if(cnt == n)return true;
        return false;
    }
};
