class Solution {
public:
    
    bool f(int mid,vector<int>&price,int k){
        int diff = mid,cnt = 1;
        int last = price[0];
        for(int i = 1;i<price.size();i++){
            if(price[i] - last >= diff){
                cnt++;
                last = price[i];
            }
        }
        if(cnt >= k)return true;
        return false;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        // [13,5,1,8,21,2]
        // [1,2,5,8,13,21]
        int n = price.size();
        sort(price.begin(),price.end());
        int i = 0,j = 1e9;
        int mid,ans = -1;
        while(i <= j){
            mid = i + (j - i)/2;
            
            if(f(mid,price,k)){
                ans = mid;
                i = mid + 1;
            }
            else j = mid - 1;
        }
        return ans;
    }
};
