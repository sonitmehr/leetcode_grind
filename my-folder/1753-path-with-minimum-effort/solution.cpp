#define pii pair<pair<int,int>,pair<int,int>>
class Solution {
public:
    int vis[101][101];
    bool valid(int i, int j,int n,int m){
        if(i < 0 || i >=n || j < 0 || j>=m)return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int> a = {-1,1,0,0}, b = {0,0,1,-1};
        priority_queue<pii,vector<pii>,greater<pii>> q;
        //if(mat[0][0] == 1)return -1;
        q.push({{0,mat[0][0]},{0,0}});
        int mini = 1e9;
        while(!q.empty()){
            auto p = q.top();
            q.pop();

            int dist = p.first.first;
            int prev = p.first.second;
            int i = p.second.first;
            int j = p.second.second;
            if(i == n - 1 && j == m - 1){
                mini = min(mini,dist);
                continue;
            }
            if(vis[i][j] == 1)continue;
            vis[i][j] = 1;
            for(int k = 0;k<=3;k++){
                int newI = i + a[k],newJ = j + b[k];
                if(valid(newI,newJ,n,m) && vis[newI][newJ] == 0){
                    int diff = abs(mat[newI][newJ] - prev);
                    diff = max(diff,dist);
                    // cout << newI << " " << newJ << " " << diff << endl;
                    q.push({{diff,mat[newI][newJ]},{newI,newJ}});
                }

            }
            
        }
        return mini;
    }
};
