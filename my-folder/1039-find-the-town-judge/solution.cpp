class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj[n+1];
        map<int,bool> m;
        for(int i =0;i<trust.size();i++){
            int a = trust[i][0],b=trust[i][1];
            adj[b].push_back(a);
            m[a] = true;
        }
        for(int i = 1;i<=n;i++){
            if(adj[i].size() == n-1 && m[i] == false)return i;
        }
        return -1;
    }

};
