class DSU {
public:
    vector<int> rank, parent, size;

    DSU(int n) {
        size.resize(n + 1, 1);
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

    void UnionByRank(int u, int v) {
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

    void UnionBySize(int u, int v) {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v)
            return;
        if (size[par_u] < size[par_v]) {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        } else {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};
class Solution {
public:
    bool check(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DSU dsu(n * m);
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int val = i * m + j;

                    for (int k = 0; k <= 3; k++) {
                        int newI = i + dx[k];
                        int newJ = j + dy[k];
                        if (check(newI, newJ, n, m) && grid[newI][newJ] == 1) {
                            int newVal = newI * m + newJ;

                            // if (dsu.findPar(val) != dsu.findPar(newVal)) {
                                dsu.UnionBySize(val, newVal);
                            // }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << i << " " << j << endl;
                int val = i * m + j;
                // cout << dsu.size[val] << endl;
                // cout << dsu.parent[val] << endl;
                int cnt = 0;
                ans= max(ans,dsu.size[val]);
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (int k = 0; k <= 3; k++) {
                        int newI = i + dx[k];
                        int newJ = j + dy[k];
                        if (check(newI, newJ, n, m) && grid[newI][newJ] == 1) {
                            int newVal = newI * m + newJ;
                            int parent = dsu.findPar(newVal);
                            if (st.find(parent) == st.end()) {

                                int sz = dsu.size[parent];
                                // cout << "Inside ";
                                // cout << newVal << " " << newJ << endl;
                                // cout << parent << " " << sz << endl;
                                cnt += sz;
                            }
                            st.insert(parent);
                        }
                    }
                }
                // cout << "cnt : " << cnt << endl;
                ans = max(ans, cnt + 1);
            }
        }
        return ans;
    }
};
