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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int cnt = connections.size();
        for(int i  = 0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];
            if(dsu.findPar(a) != dsu.findPar(b)){
                // cout << a << " " << b << endl;
                dsu.Union(a,b);
                cnt --;
            }
        }

        int rem = -1;
        for(int i = 0;i<n;i++){
            if(dsu.findPar(i) == i){
                // cout << i << endl;
                rem++;
            }
        }
        // cout << cnt << " " << rem <<endl;
        if(cnt >= rem)return rem;
        return -1;

    }
};
