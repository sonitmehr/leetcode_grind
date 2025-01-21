class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        vector<int> row(n,m);
        vector<int> col(m,n);
        for(int i = 0;i<arr.size();i++){
            int x = mp[arr[i]].first;
            int y = mp[arr[i]].second;
            row[x]--;
            col[y]--;

            if(row[x] == 0 || col[y] == 0)return i;
        }

        return 0;


    }
};
