#define pii pair<int,pair<int,int>>
class Solution {
public:
    bool valid(int i,int j,int n,int m){
        if(i < 0 || i >= n || j < 0 || j>=m)return false;
        return true;
    }
    int vis[1001][1001];
    int minimumTime(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        
        if(mat[0][1] > 1 && mat[1][0]  > 1)return -1;
        priority_queue <pii, vector<pii>, greater<pii>> q;
        
        
        q.push({0,{0,0}});
        int mini = 1e9;
        while(!q.empty()){
            auto p = q.top();
            q.pop();
            
            int time = p.first;
            int i = p.second.first,j = p.second.second;
            //cout << i << " " << j << " " << mat[i][j] << " " << time << endl;
            if(vis[i][j] == 1)continue;
            vis[i][j] = 1;
            if(i == n -1 && j == m - 1){
                return time;
            }
            vector<int> a = {-1,1,0,0}, b = {0,0,-1,1};
            
            for(int k = 0;k<=3;k++){
                int newI = i + a[k],newJ = j + b[k];
                if(valid(newI,newJ,n,m) && vis[newI][newJ] == 0){
                    int val = mat[newI][newJ];
                     int diff = val - time;
                    int add = 0;
                    if(diff%2 == 0){
                        add = 1;
                    }
                    int t = max(val + add,time + 1);
                    q.push({t,{newI,newJ}});
                }
            }
        }
        return mini;
    }
};
