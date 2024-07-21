class Solution {
public:

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};

    bool check(int i,int j,int m,int n){
        return i>=0 && j >= 0 && i< n  &&j<m;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>> q;
        int c = mat[sr][sc];
        if(c == color)return mat;
        mat[sr][sc] = color;
        q.push({sr,sc});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            auto i = p.first;
            auto j = p.second;
            for(int k = 0;k<=3;k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(check(x,y,m,n) && mat[x][y] == c){
                    q.push({x,y});
                    mat[x][y] = color;
                } 
            }
        }
        return mat;
    }
};
