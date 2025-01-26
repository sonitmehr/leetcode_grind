class Solution {
public:

    

    int maximumInvitations(vector<int>& mat) {
        int n = mat.size();

        vector<int> vis(n),inDeg(n);

        for(auto &i : mat)inDeg[i]++;

        queue<int> q;


        for(int i = 0;i<n;i++){
            if(inDeg[i] == 0)q.push(i);

        }
        vector<int> chainLen(n);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            vis[u] = 1;

            int v = mat[u];
            chainLen[v] = max(chainLen[v],1 + chainLen[u]);
            inDeg[v]--;
            if(inDeg[v] == 0)q.push(v);
        }
        int one = 0,two = 0;
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){

                int u = i,sz = 0;

                while(vis[u] == 0){
                    vis[u] = 1;
                    u = mat[u];
                    sz++;
                }

                if(sz == 2){
                    one += 2 + chainLen[u] + chainLen[mat[u]];
                }
                else{
                    two = max(two,sz);
                }
            }
        }

        return max(one,two);

    }
};
