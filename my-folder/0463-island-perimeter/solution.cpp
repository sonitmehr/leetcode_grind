class Solution {
public:
    //int ans = 0;
    int f(int i,int j,vector<vector<int>>&a,vector<vector<int>>&vis){
        if(i < 0 || j < 0 || i>=a.size() || j >= a[0].size()){
            return 1;
        }
        if(a[i][j] == 0)return 1;
        if(vis[i][j] == 1)return 0;
        
        vis[i][j] = 1;
        int ans = 0;
        ans += f(i-1,j,a,vis) + f(i+1,j,a,vis) + f(i,j-1,a,vis)+f(i,j+1,a,vis);
        
        return ans;
        
        
        
    }
    
    int islandPerimeter(vector<vector<int>>& a) {
        vector<vector<int>> vis(a.size(),vector<int>(a[0].size(),0));
        //ans = 0;
        for(int i = 0;i<a.size();i++){
            for(int j = 0;j<a[0].size();j++){
                
                if(a[i][j] == 1)return f(i,j,a,vis);
            }
        }
        return 0;
    }
};
