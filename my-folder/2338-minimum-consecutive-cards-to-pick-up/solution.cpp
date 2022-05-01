class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int maxi = INT_MAX;
        vector<int> v = cards;
        map<int,int> m;
        for(int i = 0;i<n;i++){
            if(m.find(v[i])==m.end()){
                m[v[i]] = i;
                
            }else{
                maxi = min(maxi,i - m[v[i]]+1);
                m[v[i]] = i;
            }
            
        }
        if(maxi == INT_MAX)return -1;
        return maxi;
    }
};
