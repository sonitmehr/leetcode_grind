class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        
        vector<int> ans(n,0);
        if(x > y){
            swap(x,y);
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<i;j++){
                int ind = i - j;
                ind =min(ind,abs(j - x) + abs(i - y) + 1);
                ans[ind-1] += 2;
            }
        }
        return ans;
        
    }
}; 
