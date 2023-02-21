class Solution {
public:
    int vis[10001];
    int inDegree[10001];
    vector<int> adjMat[10001];
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        for(int i = 0;i<n;i++){
            for(auto j : adj[i]){
                adjMat[j].push_back(i);
            }
        }

        for(int i = 0;i<n;i++){
            for(auto j : adjMat[i]){
                inDegree[j]++;
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout << inDegree[i] <<  " ";
        // }
        //cout << endl;
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(inDegree[i] == 0){
                //cout << i << endl;
                q.push(i);}
        }
        vector<int> ans;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            ans.push_back(p);
            for(auto i : adjMat[p]){
                inDegree[i] --;
                if(inDegree[i] == 0)q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
}; 
