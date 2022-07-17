class Solution {
public:
    vector<int> numberOfPairs(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        int pair = 0;
        for(int i = 0;i<n-1;i++){
            if(v[i] == v[i+1]){
                pair++;
                i++;
            }
        }
        return{pair,n - pair*2};
    }
};
