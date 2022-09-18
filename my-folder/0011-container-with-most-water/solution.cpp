class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        
        int i = 0,j = n -1;
        int maxi = min(v[i],v[j])*(j-i);
        while(i < j){
            
            if(v[i] >= v[j])j--;
            
            else i++;
            maxi = max(min(v[i],v[j])*(j-i),maxi);
        }
        return maxi;
    }
};
