class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        
        int ans = 0;
        vector<int> arr;
        arr.push_back(v[0]);
        for(int i= 1;i<n;i++){
            auto it = lower_bound(arr.begin(),arr.end(),v[i]);
            
            if(it == arr.end()){
                
                arr.push_back(v[i]);
            }
            else{
                arr[it - arr.begin()] = v[i];
            }
            
        }
        return arr.size();
    }
};
