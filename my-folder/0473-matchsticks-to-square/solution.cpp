class Solution {
public:
    
    bool f(int i,int sum,int target,vector<int> &a,int side,vector<bool> &check){
        
        if(side == 0)return true;
        
        if(sum == target)return f(0,0,target,a,side-1,check);
        
        for(int ii = i;ii <a.size();ii++){
            if(sum + a[ii] > target)continue;
            if(check[ii] == true)continue;
            check[ii] = true;
            //sum += a[ii];
            if(f(ii+1,sum+a[ii],target,a,side,check))return true;
            //sum-=a[ii];
            check[ii] = false;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        vector<bool> a(n,false);
        
        for(int i= 0;i<n;i++)sum += matchsticks[i];
        
        if(sum % 4 != 0)return false;

        if(n == 0)return false;
        
        return f(0,0,sum/4,matchsticks,3,a);
    }
};
