class DSU {
    vector<int> rank, parent;

public:
    DSU(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findPar(int u) {
        if (u == parent[u])
            return u;

        return parent[u] = findPar(parent[u]);
    }

    void Union(int u, int v) {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v)
            return;

        if (rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        } else if (rank[par_v] < rank[par_u]) {
            parent[par_v] = par_u;
        } else {
            parent[par_u] = par_v;
            rank[par_v]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                if (mp.find(s) == mp.end()) {
                    mp[s] = i;
                } else {
                    int prev = mp[s];
                    dsu.Union(i, prev);
                }
            }
        }
        unordered_map<int, vector<string>> ansMap;
        for (auto& i : mp) {
            string email = i.first;
            int index = i.second;
            int parent = dsu.findPar(index);
            if(ansMap.find(parent) == ansMap.end()){
                ansMap[parent] = {};
            }
            ansMap[parent].push_back(email);
        }
        vector<vector<string>> ans;

        for(int i = 0;i<n;i++){
            if(ansMap.find(i) != ansMap.end()){
                vector<string> strVec = ansMap[i];
                sort(strVec.begin(),strVec.end());
                strVec.insert(strVec.begin(),accounts[i][0]);
                ans.push_back(strVec);
            }
        }
        return ans;
    }
};
