class DSU{
    vector<int> rank,parent;
    public:
    
    DSU(int n){
        rank.resize(n + 1,0);
        parent.resize(n + 1,0);
        for(int i = 0;i<=n;i++)parent[i] = i;
    }
    
    int findPar(int u){
        if(u == parent[u])return u;
        
        return parent[u] = findPar(parent[u]);
    }
    
    void Union(int u,int v){
        int par_u = findPar(u);
        int par_v = findPar(v);
        if(par_u == par_v)return;
        
        if(rank[par_u] < rank[par_v]){
            parent[par_u] = par_v;  
        }
        else if(rank[par_v] < rank[par_u]){
            parent[par_v] = par_u;
        }
        else {
            parent[par_u] = par_v;  
            rank[par_v] ++;
        }
    }
    
    
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        DSU dsu(n);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 1){
                    dsu.Union(i,j);
                }
            }
        }
        // unordered_set<int> st;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            int par = dsu.findPar(i);
            if(par == i)cnt++;
        }
        return cnt;

    }
};
