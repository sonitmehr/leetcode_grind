class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& v) {
        int n = v.size();
        int startI = 0,startJ = 0;
        vector<vector<int>> ans(n - 2);
        int pos = -1,maxi;
        for(int k = 0;k < (n - 2)*(n-2);k ++){
            maxi = v[startI][startJ];
            for(int i = startI;i<startI + 3;i++){

                for(int j = startJ;j < startJ + 3; j++){
                    maxi = max(maxi,v[i][j]);
                    // cout << "startI " << startI << endl;
                    // cout << "startJ " << startJ << endl;
                    // cout << "maxi " << maxi << endl;
                    // cout << "i " << i << endl;
                    // cout << "j " << j << endl;
                }
            }
            ans[startI].push_back(maxi);
            startJ++;
            if(startJ == n -2){
                startI++;
                startJ = 0;
            }
            if(startI == n - 2)break;
        }
        
        return ans;
    }
};
