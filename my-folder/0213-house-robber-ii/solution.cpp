class Solution {
public:
    
    int f(int i,vector<int> &dp,vector<int> &a){
        if(i == 0)return a[i];
        if(i < 0)return 0;
        if(dp[i]!=-1)return dp[i];
        
        
        int l = a[i] + f(i-2,dp,a);
        int r = f(i-1,dp,a);
                
        return dp[i]=max(l,r);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp1(n,-1);
        vector<int> exceptFirstEle(n-1);
        vector<int> exceptLastEle(n-1);
        
        int ptr1=0,ptr2 = 0;
        for(int i =0;i<n;i++){
            if(i!=0){
                exceptFirstEle[ptr1] = nums[i];
                ptr1++;
            }
            if(i!=(n-1)){
                exceptLastEle[ptr2] = nums[i];
                ptr2++;
            }
        }
        cout << "exceptLastEle " << endl;
        for(auto i : exceptLastEle)cout << i << " ";
        cout << "\n" << "exceptFirstEle " << endl;
        for(auto i : exceptFirstEle)cout << i << " ";
        
        int r = f(n-2,dp,exceptLastEle);
        int l = f(n-2,dp1,exceptFirstEle);
        return max(l,r);
    }
};
