class Solution {
public:
    # define ll long long
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        long long n = rocks.size();
        
        vector<int> diff(n);
        
        for(int i = 0;i<n;i++){
            diff[i] = capacity[i] - rocks[i];
        }
        sort(diff.begin(),diff.end());
        long long cnt = 0;
        for(int i = 0;i<n;i++){
            
            if(additionalRocks < diff[i])break;
            additionalRocks -= diff[i];
            cnt++;
            
        }
        return cnt;
            
        
    }
};
