class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n = v.size();
        int maxi = 0;
        map<int,int> m;
        for(int i = 0;i<n;i++){
            
            maxi = max(maxi,v[i]);
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            if(v[i]== 1 || v[i] == maxi){
                int j = i;
                while(j< n && (v[j] == 1 || v[j] == maxi)){
                    j++;
                }
                ans = max(ans,j-i);
                i = j;
            }
        }
        return max(1,ans);
    }
};
