class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        long long n = special.size();
        sort(special.begin(),special.end());
        
        int maxi = 0;
        
        for(int i=1;i<n;i++){
            maxi = max(maxi,(special[i]- special[i-1]-1));
        } 
        maxi = max(maxi,max(special[0] - bottom,top - special[n-1]));
        
        return maxi;
    }
};
