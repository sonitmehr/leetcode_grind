class Solution {
public:

    int f(int i,int prev,vector<int>&arr1,vector<int>&arr2,vector<unordered_map<int,int>> &dp){
        if(i == arr1.size())return 0;

        if(dp[i][prev] > 0)return dp[i][prev];

        int leave = 1e9;
        int replace = 1e9;

        if(arr1[i] > prev) leave = f(i + 1,arr1[i],arr1,arr2,dp);

        int rep = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();

        if(rep == arr2.size())replace = 1e9;
        else{
            replace = f(i + 1,arr2[rep],arr1,arr2,dp);
        }

        return dp[i][prev] = min(leave,replace + 1);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<unordered_map<int,int>> dp(2001);
        int val = f(0,INT_MIN,arr1,arr2,dp);
        if(val != 1e9)return val;
        return -1;

    }
};
