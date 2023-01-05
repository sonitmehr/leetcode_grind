class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        long long maxi = v[0][1],ans = 1;
        for(int i = 1;i<n;i++){
            cout << maxi << endl;
            if(v[i][0] > maxi){
                maxi = v[i][1];
                ans++;
            }
            maxi = min(maxi,(long long)v[i][1]);
        }
        return ans;
    }
};
