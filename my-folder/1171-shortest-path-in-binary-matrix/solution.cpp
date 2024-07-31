#define pii pair<int,pair<int,int>>
class Solution {
public:
    int vis[101][101];
    bool valid(int i, int j,int n,int m){
        if(i < 0 || i >=n || j < 0 || j>=m)return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int> a = {-1,-1,-1,1,1,1,0,0}, b = {0,-1,1,0,-1,1,-1,1};
        priority_queue<pii,vector<pii>,greater<pii>> q;
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        if(mat[0][0] == 1)return -1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto p = q.top();
            q.pop();

            int distance = p.first;
            int i = p.second.first;
            int j = p.second.second;
            if(i == n - 1 && j == m - 1)return distance;
            for(int k = 0;k<=7;k++){
                int newI = i + a[k];
                int newJ = j + b[k];
                if(valid(newI,newJ,n,m) && mat[newI][newJ] == 0 && distance + 1 < dist[newI][newJ]){
                    dist[newI][newJ] = distance + 1;
                    q.push({distance + 1,{newI,newJ}});

                }

            }
            
        }
        return -1;
        
    }
};
