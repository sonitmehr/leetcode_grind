class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int> temp;
        int n = v.size();
        temp.push_back(v[0]);
        for(int i = 1;i<n;i++){
            if(v[i] > temp.back()) temp.push_back(v[i]);
            
            else {
                auto ind = lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin();
                
                temp[ind] = v[i];
            }
            
        }
        return temp.size();
        
    }
};
