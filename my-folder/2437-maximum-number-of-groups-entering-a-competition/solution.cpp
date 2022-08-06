class Solution {
public:
    int maximumGroups(vector<int>& v) {
        int n = v.size();
        
        vector<int> ans;
       // ans.push_back(0);
        int sum = 0,i = 1;
        while(sum < n){
            sum += i;
            if(ans.size() > 0 && sum > n){
                ans.back() += (n - ans.back() -1 );
            }
            else ans.push_back(i);
            i++;
            
            //i++;
            
        }
        
        return ans.size();
    }
};
