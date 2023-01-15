class Solution {
public:
// Video refered https://www.youtube.com/watch?v=d9G9u5zvMZs&ab_channel=ThinkthenCode
    int parent[100001];
    int R[100001]; // Rank 

    void makeSet(){
        for(int i = 0;i<=100000;i++){
            parent[i] = i;
            R[i] = 0;
        }
    }
    int findPar(int node){
        if(node == parent[node])return node; // When the parent of node is the node itself.
        return parent[node] = findPar(parent[node]); // Searches for parent in constant time.
    }
    void Union(int u,int v){
        u = findPar(u);
        v = findPar(v);
        
        if(u!=v){
            parent[v] = u;
        }
    }
        int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<pair<int,vector<int>>> vec;
        makeSet();
        for(int i = 0;i<n;i++){
            int a = edges[i][0];
            int b = edges[i][1];
            vec.push_back({max(vals[a],vals[b]),edges[i]});
        }
        sort(vec.begin(),vec.end());
        
        int m = vals.size();
        int ans = m;
        vector<unordered_map<int,int>> freq(m);
        for(int i =0;i<m;i++){
            freq[i][vals[i]] = 1;
        }
        for(auto it : vec){
            int u = it.second[0], v = it.second[1];
            int maxi = max(vals[u],vals[v]);

            int uParent = findPar(u);
            int vParent = findPar(v);
            Union(u,v);
            // cout << u << " " << v << " " << uParent << " " << vParent << " ";
            // cout << freq[uParent][maxi] << " " << freq[vParent][maxi] << endl;
            ans += freq[uParent][maxi]*freq[vParent][maxi];

            freq[uParent][maxi] += freq[vParent][maxi];
            freq[vParent].erase(maxi);

        }
        return ans;


        return 0;


    }
};
