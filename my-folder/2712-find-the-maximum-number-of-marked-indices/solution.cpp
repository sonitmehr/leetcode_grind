class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        sort(v.begin(),v.end());
        //for(auto i : v)cout << i << " ";
        int n =v.size();
        int i = 0,j = n/2,ans = 0;
        while(i < n/2 && j < n){
            if(2*v[i] <= v[j]){
                ans += 2;
                i ++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};
