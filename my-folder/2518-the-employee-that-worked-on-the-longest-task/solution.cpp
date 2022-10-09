class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& v) {
        int m = v.size();
        
        vector<int> id(n,0);
        int prev = 0,ans = 0,prevId = v[0][0];
        int maxi = 0;
        for(int i = 0;i<m;i++){
            int ID = v[i][0];
            int end = v[i][1];
            if(end - prev > maxi){
                ans = ID;
                maxi = end - prev;
            }
            else if(end - prev == maxi){
                ans = min(ans,ID);
            }
            prevId = ID;
            
            prev = end;
        }
        
        return ans;
        
        
        
    }
};
