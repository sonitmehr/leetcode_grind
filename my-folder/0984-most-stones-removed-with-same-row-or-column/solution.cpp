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
    int removeStones(vector<vector<int>>& stones) {
        int sz = 2 * 1e4 + 2;
        DSU dsu(sz);
        int diff = 1e4 + 1;
        int n = stones.size();
        for(int i = 0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1] + diff;

            if(dsu.findPar(x) != dsu.findPar(y)){
                dsu.Union(x,y);
            }
        }
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1] + diff;

            int par_x = dsu.findPar(x);
            int par_y = dsu.findPar(y);

            st.insert(par_x);
            st.insert(par_y);
        }
        return n - st.size();
    }
};
