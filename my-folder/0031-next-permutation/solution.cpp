class Solution {
public:
    int findEle(vector<int> &v,int ele,int end){
        int n = v.size();
        
        for(int i= n-1;i>end;i--){
            if(v[i] > ele)return i;
        }
        return -1;
        
    }
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        
        for(int i= n-2;i>=0;i--){
            if(v[i+1] > v[i] ){
                //auto upperInd = upper_bound(v.begin(), v.end(),v[i]);
                //auto it = std::find (v.begin(), v.end(), upperInd ));
                int val = findEle(v,v[i],i);
                cout << val;
                swap(v[val],v[i]);
                reverse(v.begin() + i + 1,v.end());
                return;
                
                
                
            }
        }
        reverse(v.begin(),v.end());
        return;
        
    }
};
