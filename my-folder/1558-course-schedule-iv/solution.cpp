class Solution {
public:
    stack<int> st;
    int vis[101];
    vector<int> adj[101];
    void f(int node){
        vis[node] = 1;

        for(auto i : adj[node]){
            if(vis[i] == 0){
                f(i);
            }
        }
        //st.push(node);
        
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& v, vector<vector<int>>& queries) {
        if(v.size() == 0){
            vector<bool> anss;
            for(auto i : queries){
                anss.push_back(0);
            }
            return anss;
        }
        for(auto i : v){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool> ans;
        for(auto q : queries){
            int a = q[0],b = q[1];
            memset(vis,0,sizeof(vis));
            f(a);
            if(vis[b] == 1)ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
        

    }
};
